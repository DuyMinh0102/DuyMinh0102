// Source: https://marisaoj.com/problem/423
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 15/07/2026 (DD/MM/YYYY).
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
const int MOD = 1000000007;
const ll INF = 2e18;

// Variables
struct node {
  ll mx = 0, mn = INF;

  node() {}

  node(ll _mx, ll _mn) : mx(_mx), mn(_mn) {}
} t[4 * N];

int n;
ll ans = 0, arr[N];

void build(int k, int l, int r) {
  if (l > r)
    return;
  if (l == r) {
    t[k].mx = t[k].mn = arr[l];
    return;
  }

  int mid = l + ((r - l) >> 1);
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);

  t[k].mx = max(t[k << 1].mx, t[k << 1 | 1].mx);
  t[k].mn = min(t[k << 1].mn, t[k << 1 | 1].mn);
}

node query(int k, int l, int r, int lim_l, int lim_r) {
  if (r < lim_l || l > lim_r || l > r)
    return node(0, INF);
  if (lim_l <= l && r <= lim_r)
    return t[k];

  int mid = l + ((r - l) >> 1);

  node a = query(k << 1, l, mid, lim_l, lim_r),
       b = query(k << 1 | 1, mid + 1, r, lim_l, lim_r);

  return node(max(a.mx, b.mx), min(a.mn, b.mn));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 1; i <= n; ++i)
    cin >> arr[i];

  build(1, 1, n);

  for (int i = 1; i <= n; ++i) {
    node cur = query(1, 1, n, i, n);

    ans = (ans % MOD + (n + i - 1) * ((cur.mx % MOD) * (cur.mn % MOD)) % MOD) %
          MOD;
  }

  cout << ans << '\n';
}
