// Source: No source
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 11/05/2026 (DD/MM/YYYY).
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
const int N = 1e5 + 5;
const ll INF = 1e18;

// Variables
int n, q;
ll v[N], c[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("balls.inp", "r", stdin);
  freopen("balls.out", "w", stdout);

  cin >> n >> q;

  for (int i = 1; i <= n; ++i)
    cin >> v[i];
  for (int i = 1; i <= n; ++i)
    cin >> c[i];

  while (q--) {
    vector<ll> mx_dp(n + 1, -INF);
    ll a, b;
    cin >> a >> b;

    ll mx1 = 0, mx2 = 0;
    int c_mx1 = 0, c_mx2 = -1;

    for (int i = 1; i <= n; ++i) {
      int cl = c[i];
      ll val = v[i], ans_i = val * b;

      if (mx_dp[cl] != -INF) {
        ans_i = max(ans_i, mx_dp[cl] + val * a);
      }

      if (c_mx1 != cl) {
        ans_i = max(ans_i, mx1 + val * b);
      } else {
        ans_i = max(ans_i, mx2 + val * b);
      }

      mx_dp[cl] = max(mx_dp[cl], ans_i);

      if (ans_i > mx1) {
        if (cl == c_mx1) {
          mx1 = ans_i;
        } else {
          mx2 = mx1;
          c_mx2 = c_mx1;
          mx1 = ans_i;
          c_mx1 = cl;
        }
      } else if (ans_i > mx2 && cl != c_mx1) {
        mx2 = ans_i;
        c_mx2 = cl;
      }
    }

    cout << mx1 << '\n';
  }
}
