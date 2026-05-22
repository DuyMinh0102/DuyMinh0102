// Source: https://codeforces.com/contest/2/problem/B
// Status: Solved
/*
Note:
Trailing zeros are formed by pairs of 2 and 5. We need to minimize the number of
10s, which is min(count of 2s, count of 5s) in the product's prime
factorization. We can solve this by running DP twice: once to minimize factors
of 2, and once for factors of 5.

Solution:
Calculate the number of 2s and 5s for each cell.
Use DP to find the minimum accumulation of 2s and 5s to reach (n, n), keeping
track of the path ('D' or 'R'). Special case: If the matrix contains a 0, the
answer is at most 1 (since 0 has 1 trailing zero). If the DP yields an answer >
0 and 0 exists in the matrix, we force the path to pass through the 0.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 19/05/2026 (DD/MM/YYYY).
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
const int N = 1005;
int n, zx = 0;
int a[N][N];
int d2[N][N], d5[N][N];
char p2[N][N], p5[N][N];

int f2(int x) {
  if (!x)
    return 1;
  int c = 0;
  while (x % 2 == 0) {
    c++;
    x /= 2;
  }
  return c;
}

int f5(int x) {
  if (!x)
    return 1;
  int c = 0;
  while (x % 5 == 0) {
    c++;
    x /= 5;
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0)
        zx = i;
      d2[i][j] = d5[i][j] = 1e9;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 && j == 1) {
        d2[i][j] = f2(a[i][j]);
        d5[i][j] = f5(a[i][j]);
        continue;
      }

      int c2 = f2(a[i][j]);
      int c5 = f5(a[i][j]);

      int up2 = (i > 1) ? d2[i - 1][j] : 1e9;
      int left2 = (j > 1) ? d2[i][j - 1] : 1e9;
      if (up2 < left2) {
        d2[i][j] = up2 + c2;
        p2[i][j] = 'D';
      } else {
        d2[i][j] = left2 + c2;
        p2[i][j] = 'R';
      }

      int up5 = (i > 1) ? d5[i - 1][j] : 1e9;
      int left5 = (j > 1) ? d5[i][j - 1] : 1e9;
      if (up5 < left5) {
        d5[i][j] = up5 + c5;
        p5[i][j] = 'D';
      } else {
        d5[i][j] = left5 + c5;
        p5[i][j] = 'R';
      }
    }
  }

  int ans = min(d2[n][n], d5[n][n]);

  if (zx && ans > 0) {
    cout << 1 << '\n';
    for (int i = 1; i < zx; i++)
      cout << 'D';
    for (int j = 1; j < n; j++)
      cout << 'R';
    for (int i = zx; i < n; i++)
      cout << 'D';
    cout << '\n';
    return 0;
  }

  cout << ans << '\n';
  string path = "";
  int r = n, c = n;

  if (d2[n][n] < d5[n][n]) {
    while (r > 1 || c > 1) {
      path += p2[r][c];
      if (p2[r][c] == 'D')
        r--;
      else
        c--;
    }
  } else {
    while (r > 1 || c > 1) {
      path += p5[r][c];
      if (p5[r][c] == 'D')
        r--;
      else
        c--;
    }
  }

  reverse(path.begin(), path.end());
  cout << path << '\n';

  return 0;
}
