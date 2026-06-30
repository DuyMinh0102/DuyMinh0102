// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
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
string s, t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> t;

  string tmp;
  int tsz = t.size();
  for (char c : s) {
    tmp += c;
    if (tmp.size() < tsz)
      continue;
    if (tmp.substr(tmp.size() - tsz, tsz) == t) {
      for (int i = 0; i < tsz; ++i)
        tmp.pop_back();
    }
  }
  cout << tmp;
}
