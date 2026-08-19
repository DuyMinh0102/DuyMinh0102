// Source: https://codeforces.com/problemset/problem/833/B
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 35005;
const int K_MAX = 55;
const int INF = 1e9;

// Variables
int n, k, a[N], lst_pos[N], nxt_pos[N];

int dp[K_MAX][N];

struct node {
  int sum, lc, rc;
} t[N * 40];
int root[N], nodecnt = 0;

int insert(int prev, int l, int r, int pos, int val) {
  int curr = ++nodecnt;
  t[curr] = t[prev];
  t[curr].sum += val;

  if (l == r)
    return curr;

  int mid = l + ((r - l) >> 1);
  if (pos <= mid)
    t[curr].lc = insert(t[prev].lc, l, mid, pos, val);
  else
    t[curr].rc = insert(t[prev].rc, mid + 1, r, pos, val);

  return curr;
}

int query(int curr, int l, int r, int liml, int limr) {
  if (!curr || l > limr || r < liml)
    return 0;
  if (liml <= l && r <= limr)
    return t[curr].sum;

  int mid = l + ((r - l) >> 1);
  return query(t[curr].lc, l, mid, liml, limr) +
         query(t[curr].rc, mid + 1, r, liml, limr);
}

int get(int l, int r) {
  if (l > r)
    return 0;
  return query(root[r], 1, n, l, r);
}

void compute(int k_idx, int l, int r, int optl, int optr) {
  if (l > r)
    return;

  int mid = l + ((r - l) >> 1);
  int best_val = -1, best_opt = -1;

  int lim = min(mid - 1, optr);

  int start_m = max(optl, k_idx - 1);

  if (start_m <= lim) {
    int cost = get(start_m + 1, mid);

    for (int m = start_m; m <= lim; ++m) {
      if (dp[k_idx - 1][m] != -1) {
        int cur = dp[k_idx - 1][m] + cost;

        if (cur > best_val) {
          best_val = cur;
          best_opt = m;
        }
      }

      if (nxt_pos[m + 1] > mid)
        --cost;
    }
  }

  dp[k_idx][mid] = best_val;

  if (best_opt != -1) {
    compute(k_idx, l, mid - 1, optl, best_opt);
    compute(k_idx, mid + 1, r, best_opt, optr);
  } else {
    compute(k_idx, l, mid - 1, optl, optr);
    compute(k_idx, mid + 1, r, optl, optr);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  if (!(cin >> n >> k))
    return 0;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = 1; i <= n; ++i)
    lst_pos[i] = n + 1;
  for (int i = n; i >= 1; --i) {
    nxt_pos[i] = lst_pos[a[i]];
    lst_pos[a[i]] = i;
  }

  memset(lst_pos, 0, sizeof(lst_pos));
  root[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int rt = root[i - 1];

    if (lst_pos[a[i]] != 0)
      rt = insert(rt, 1, n, lst_pos[a[i]], -1);

    rt = insert(rt, 1, n, i, 1);
    root[i] = rt;

    lst_pos[a[i]] = i;
  }

  for (int j = 0; j <= k; ++j) {
    for (int i = 0; i <= n; ++i) {
      dp[j][i] = -1;
    }
  }

  for (int i = 1; i <= n; ++i)
    dp[1][i] = get(1, i);

  for (int j = 2; j <= k; ++j)
    compute(j, 1, n, 1, n);

  cout << dp[k][n] << "\n";

  return 0;
}
