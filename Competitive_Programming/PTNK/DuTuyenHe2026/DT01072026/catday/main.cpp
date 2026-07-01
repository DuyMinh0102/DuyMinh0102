// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
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
#define db double
const int N = 5005;
const ll INF = 1e18;

// Variables
int n, k;
ll a[N], dp[2][N];
struct line {
  ll m, b;
  ll val(ll x) { return m * x + b; }
} tree[4 * N];

void build(int k, int l, int r) {
  tree[k] = {0, INF};
  if (l == r)
    return;
  int mid = l + ((r - l) >> 2);
  build(k << 1, l, mid);
  build((k << 1) | 1, mid + 1, r);
}

void insert(int k, int l, int r, line newline) {
  int mid = l + ((r - l) >> 1);
  bool left = newline.val(a[l]) < tree[k].val(a[l]);
  bool md = newline.val(a[mid]) < tree[k].val(a[mid]);

  if (md)
    swap(tree[k], newline);
  if (l == r)
    return;

  if (left != md)
    insert(k << 1, l, mid, newline);
  else
    insert((k << 1) | 1, mid + 1, r, newline);
}

ll query(int k, int l, int r, int id) {
  ll res = tree[k].val(a[id]);
  if (l == r)
    return res;

  int mid = l + ((r - l) >> 1);
  if (id <= mid)
    return min(res, query(k << 1, l, mid, id));
  else
    return min(res, query((k << 1) | 1, mid + 1, r, id));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];

    dp[1][i] = a[i] * a[i];
  }

  for (int K = 2; K <= k; ++K) {
    build(1, 1, n);
    int cur = K % 2, prv = 1 - cur;

    insert(1, 1, n, {2 * a[K - 1], dp[prv][K - 1] + a[K - 1] * a[K - 1]});

    for (int i = K; i <= n; ++i) {
      dp[cur][i] = query(1, 1, n, i) + a[i] * a[i];

      insert(1, 1, n, {-2 * a[i], dp[prv][i] + a[i] * a[i]});
    }
  }

  cout << dp[k % 2][n];
}
