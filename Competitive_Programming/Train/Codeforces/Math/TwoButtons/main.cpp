// Source: https://codeforces.com/contest/520/problem/B
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 06/07/2026 (DD/MM/YYYY).
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
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  if (n > m)
    cout << n - m;
  else {
    int cnt = 0;
    while (m > n) {
      if (m & 1)
        ++m;
      else
        m /= 2;
      ++cnt;
    }

    cnt += (n - m);
    cout << cnt;
  }
}
