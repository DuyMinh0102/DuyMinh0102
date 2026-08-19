// Source: https://codeforces.com/contest/1155/problem/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 25/07/2026 (DD/MM/YYYY).
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

// Variables
int n;
ll x;
int a[300005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x;
  ll dp0 = 0, dp1 = 0, dp2 = 0;

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll val;
    cin >> val;

    dp2 = max(dp1 + val, dp2 + val);
    dp1 = max(dp0 + val * x, dp1 + val * x);
    dp0 = max(0LL, dp0 + val);

    ans = max({ans, dp0, dp1, dp2});
  }

  cout << ans;
}
