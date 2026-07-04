// Source: https://codeforces.com/contest/1513/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 04/05/2026 (DD/MM/YYYY).
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
const ll MOD = 1e9 + 7;
const int MAXM = 2e5 + 10;

// Variables
int t, m;
string n;
ll dp[MAXM];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  for (int i = 0; i < 10; ++i)
    dp[i] = 1;
  for (int i = 10; i < MAXM; ++i)
    dp[i] = (dp[i - 9] + dp[i - 10]) % MOD;

  while (t--) {
    cin >> n >> m;

    ll len = 0;
    for (char c : n) {
      int cur = c - '0';

      len = (len + dp[m + cur]) % MOD;
    }

    cout << len << '\n';
  }
}
