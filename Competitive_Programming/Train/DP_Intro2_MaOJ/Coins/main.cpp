// Source: https://marisaoj.com/problem/151
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 30/05/2026 (DD/MM/YYYY).
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
int n, k;
ll dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  dp[0] = 0;
  for (int i = 1; i < N; ++i)
    dp[i] = INF;

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[j] <= i)
        dp[i] = min(dp[i], dp[i - a[j]] + 1);
    }
  }

  if (dp[k] == INF)
    cout << -1;
  else
    cout << dp[k];
}
