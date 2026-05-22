// Source: https://codeforces.com/contest/1625/problem/C
// Status: Unsolved
/*
Note: A road with length L, with n signs each has n different coordinates, and
on each sign is a speed limit. Speed limit: from sign a_i to a_(i + 1) you'll
take a_i minutes each kilometre. Remove at most k signs so the time to move from
0 to L is minimize.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 18/05/2026 (DD/MM/YYYY).
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
const ll INF = 1e18;

// Variables
int n, l, k;
vector<ll> d, s_lim;
vector<vector<ll>> dp(505, vector<ll>(505, INF));

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> l >> k;

  d.resize(n + 1, 0);
  s_lim.resize(n + 1, 0);

  for (int i = 0; i < n; ++i)
    cin >> d[i];

  for (int i = 0; i < n; ++i)
    cin >> s_lim[i];

  d[n] = l;
  s_lim[n] = 0;

  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (dp[i][j] == INF) continue;
      for (int p = i + 1; p <= n; ++p) {
        int rem = p - i - 1;

        if (rem + j <= k){
          dp[p][j + rem] = min(dp[p][j + rem], dp[i][j] + (d[p] - d[i])*s_lim[i]);
        }
      }
    }
  }

  ll ans = INF;
  for (int j = 0; j <= k; ++j){
    ans = min(dp[n][j], ans);
  }

  cout << ans;
}
