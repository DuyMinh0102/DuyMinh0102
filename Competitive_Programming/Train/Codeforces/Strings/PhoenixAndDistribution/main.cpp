// Source: https://codeforces.com/contest/1348/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 09/07/2026 (DD/MM/YYYY).
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
int t, n, k;
string s;

void solve() {
  cin >> n >> k >> s;
  sort(s.begin(), s.end());

  if (s[0] != s[k - 1]) {
    cout << s[k - 1];
    return;
  }

  cout << s[0];

  if (s[k] != s[n - 1]) {
    for (int i = k; i < n; ++i)
      cout << s[i];
    return;
  }

  for (int i = 0; i < (n - 1) / k; ++i)
    cout << s[n - 1];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
