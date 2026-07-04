// Source: https://marisaoj.com/problem/148
// Status: Solved
/*
Note: There's a game, each turn you either take away the first or the last
element of the array. You'll get x points, where x is the value of the element
you took. There's two players Marisa and Reimu, each of their total points
respectively are x and y. Marisa's goal is to maximize x - y, while Reimu is to
minimize it. Determine the highest possible value of x - y if both of them play
optimally.

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
const int N = 5005;

// Variables
int n, a[N];
ll dp[N][N][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    dp[i][i][0] = a[i];
    dp[i][i][1] = -a[i];
  }

  for (int l = 2; l <= n; ++l) {
    for (int i = 1; i + l - 1 <= n; ++i) {
      int j = i + l - 1;
      dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j]);
      dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j]);
    }
  }

  cout << dp[1][n][0];
}
