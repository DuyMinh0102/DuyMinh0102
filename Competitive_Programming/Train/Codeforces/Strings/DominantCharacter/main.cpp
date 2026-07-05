// Source: https://codeforces.com/contest/1605/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 05/07/2026 (DD/MM/YYYY).
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
string s;

void solve() {
  cin >> n >> s;

  if (s.find("aa") != string::npos)
    cout << 2 << '\n';
  else if (s.find("aba") != string::npos || s.find("aca") != string::npos)
    cout << 3 << '\n';
  else if (s.find("abca") != string::npos || s.find("acba") != string::npos)
    cout << 4 << '\n';
  else if (s.find("abbacca") != string::npos ||
           s.find("accabba") != string::npos)
    cout << 7 << '\n';
  else
    cout << -1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
