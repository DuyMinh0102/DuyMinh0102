// Source: https://codeforces.com/problemset/problem/786/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 21/07/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 100005;
const int MAXNODE = 4000005;

// Variables
int n, nodecnt = 0;
int a[N], root[N], nxt[N];

struct Node {
  int sum, lc, rc;
} t[MAXNODE];

int update(int prev, int l, int r, int pos, int val) {
  int cur = ++nodecnt;
  t[cur] = t[prev];
  t[cur].sum += val;
  if (l == r)
    return cur;

  int mid = l + ((r - l) >> 1);
  if (pos <= mid)
    t[cur].lc = update(t[cur].lc, l, mid, pos, val);
  else
    t[cur].rc = update(t[cur].rc, mid + 1, r, pos, val);

  t[cur].sum = t[t[cur].lc].sum + t[t[cur].rc].sum;
  return cur;
}

int query(int node, int l, int r, int k) {
  if (t[node].sum <= k)
    return r;
  if (l == r)
    return l - 1;

  int mid = l + ((r - l) >> 1);
  int l_sum = t[t[node].lc].sum;

  if (l_sum > k)
    return query(t[node].lc, l, mid, k);

  return query(t[node].rc, mid + 1, r, k - l_sum);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = n; i >= 1; --i) {
    int tmp = update(root[i + 1], 1, n, i, 1);

    if (nxt[a[i]] != 0)
      root[i] = update(tmp, 1, n, nxt[a[i]], -1);
    else
      root[i] = tmp;

    nxt[a[i]] = i;
  }

  for (int k = 1; k <= n; ++k) {
    int squad = 0, id = 1;

    while (id <= n) {
      ++squad;

      int mx_right = query(root[id], 1, n, k);

      id = mx_right + 1;
    }
    cout << squad << ' ';
  }
}
