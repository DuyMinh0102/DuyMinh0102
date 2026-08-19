// Source: https://codeforces.com/problemset/problem/453/A
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 31/07/2026 (DD/MM/YYYY).
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
ll m, n;

double binpow(double x, int y) {
  double res = 1.0;

  while (y) {
    if (y & 1)
      res *= x;
    x *= x;
    y >>= 1;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> m >> n;

  double ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans += 1.0 * (binpow(1.0 * i / m, n) - binpow(1.0 * (i - 1) / m, n)) * i;
  }

  cout << fixed << setprecision(12) << ans;
}
