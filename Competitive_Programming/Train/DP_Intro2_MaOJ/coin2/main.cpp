// Source: https://marisaoj.com/problem/158
// Status: Solved
/*
Note: There are n types of coins, the ith coin is worth A_i. You have to pay a
debt of k, how many ordered ways of choosing coins are there to create k.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 02/06/2026 (DD/MM/YYYY).
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
const ll MOD = 1e9 + 7;

// Variables
int n, k;
int a[1005];
ll dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  sort(a + 1, a + n + 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = a[i]; j <= k; ++j) {
      dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
    }
  }

  cout << dp[k];
}
