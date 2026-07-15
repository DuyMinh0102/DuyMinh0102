// Source: https://codeforces.com/contest/1383/problem/A
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 13/07/2026 (DD/MM/YYYY).
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
int t, n;
string a, b;

void solve() {
  cin >> n;

  cin >> a >> b;
  for (int i = 0; i < n; ++i)
    if (a[i] > b[i]) {
      cout << -1 << '\n';
      return;
    }

  int op = 0;

  for (char c = 'a'; c < 't'; ++c) {
    char mn = 'z';

    for (int i = 0; i < n; ++i)
      if (a[i] == c && a[i] != b[i])
        mn = min(mn, b[i]);

    if (mn != 'z') {
      ++op;

      for (int i = 0; i < n; ++i)
        if (a[i] == c && a[i] != b[i])
          a[i] = mn;
    }
  }

  cout << op << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
