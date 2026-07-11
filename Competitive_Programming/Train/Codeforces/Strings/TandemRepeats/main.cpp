// Source: https://codeforces.com/contest/1948/problem/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 10/07/2026 (DD/MM/YYYY).
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
int n, t;
string s;

void solve() {
  cin >> s;
  n = s.size();

  for (int d = n / 2; d >= 1; --d) {
    int match = 0;

    for (int i = 0; i < n - d; ++i) {
      if (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?') {
        ++match;

        if (match == d) {
          cout << 2 * d << '\n';
          return;
        }
      } else
        match = 0;
    }
  }

  cout << 0 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
