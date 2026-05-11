// Source: https://codeforces.com/contest/1695/problem/C
// Status: Solved
/*
Note: A grid size n x m with every cells can only be 1 or -1.
Determine if there is a path from (1, 1) to (n, m) so that the sum of the path
is 0.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 10/05/2026 (DD/MM/YYYY).
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
int t, n, m;

void solve() {
  cin >> n >> m;

  vector<vector<int>> g(n + 1, vector<int>(m + 1)),
      mn_dp(n + 1, vector<int>(m + 1, 2 * (n + m))),
      mx_dp(n + 1, vector<int>(m + 1, -2 * (n + m)));

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> g[i][j];
    }
  }

  if ((n + m - 1) & 1) {
    cout << "NO";
    return;
  }

  mn_dp[1][1] = mx_dp[1][1] = g[1][1];

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i == 1 && j == 1)
        continue;

      int mn_prev = 2 * (n + m), mx_prev = -2 * (n + m + 1);

      if (i > 1) {
        mn_prev = min(mn_prev, mn_dp[i - 1][j]);
        mx_prev = max(mx_prev, mx_dp[i - 1][j]);
      }
      if (j > 1) {
        mn_prev = min(mn_prev, mn_dp[i][j - 1]);
        mx_prev = max(mx_prev, mx_dp[i][j - 1]);
      }

      mn_dp[i][j] = mn_prev + g[i][j];
      mx_dp[i][j] = mx_prev + g[i][j];
    }
  }

  if (mn_dp[n][m] <= 0 && mx_dp[n][m] >= 0)
    cout << "YES";
  else
    cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    solve();
    cout << '\n';
  }
}
