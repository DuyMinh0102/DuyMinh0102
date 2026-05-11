// Source: https://codeforces.com/contest/577/problem/B
// Status: Solved
/*
Note: Choose a subset from the original sequence so that it's sum is divisible
by m.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 08/05/2026 (DD/MM/YYYY).
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
const int N = 1e6 + 5;

// Variables
ll n, m;
ll a[N];
vector<bool> dp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  dp.resize(m + 1, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] %= m;
  }

  if (n <= m) {
    for (int i = 1; i <= n; ++i) {
      vector<bool> nxt_dp(m + 1, false);

      nxt_dp[a[i] % m] = true;

      for (int j = 0; j < m; ++j) {
        if (dp[j]) {
          nxt_dp[j] = true;
          nxt_dp[(j + a[i]) % m] = true;
        }
      }

      dp = nxt_dp;

      if (dp[0]) {
        cout << "YES";
        return 0;
      }
    }
  } else {
    cout << "YES";
    return 0;
  }

  cout << "NO";
}
