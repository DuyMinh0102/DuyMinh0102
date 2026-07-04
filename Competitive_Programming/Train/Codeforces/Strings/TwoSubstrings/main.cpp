// Source: https://codeforces.com/contest/550/problem/A
// Status: Unsolved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 30/06/2026 (DD/MM/YYYY).
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
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  bool possible = false;

  auto first_ab = s.find("AB");
  if (first_ab != string::npos)
    if (s.find("BA", first_ab + 2) != string::npos)
      possible = true;

  auto first_ba = s.find("BA");
  if (first_ba != string::npos)
    if (s.find("AB", first_ba + 2) != string::npos)
      possible = true;

  if (possible)
    cout << "YES";
  else
    cout << "NO";
}
