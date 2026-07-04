// Source: https://codeforces.com/contest/1398/problem/D
// Status: Solved
/*
Note: Given R, G, B pairs of red, green and blue colored sticks. You can pick
two pairs of different color to create a rectangle. Determine the largest total
area that can be created.

Solution: Sort all arrays descendingly.
Do N^3 brute force dp to calculate, record the maximum into a variable.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 22/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                   \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 205;

// Variables
int R, G, B;
ll r[N], g[N], b[N];
ll dp[N][N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> R >> G >> B;
  r[0] = g[0] = b[0] = 0;
  for (int i = 0; i < R; ++i) cin >> r[i];

  for (int i = 0; i < G; ++i) cin >> g[i];

  for (int i = 0; i < B; ++i) cin >> b[i];
  sort(r, r + R, greater<int>());
  sort(g, g + G, greater<int>());
  sort(b, b + B, greater<int>());

  ll mx = 0;

  for (int i = 0; i <= R; ++i) {
    for (int j = 0; j <= G; ++j) {
      for (int k = 0; k <= B; ++k) {
        if (i > 0 && j > 0) {
          dp[i][j][k] =
              max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
        }
        if (i > 0 && k > 0) {
          dp[i][j][k] =
              max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i - 1] * b[k - 1]);
        }
        if (j > 0 && k > 0) {
          dp[i][j][k] =
              max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
        }

        mx = max(mx, dp[i][j][k]);
      }
    }
  }

  cout << mx;
}
