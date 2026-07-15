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
int t, n;

void solve() {
  cin >> n;

  unordered_set<string> freq;

  bool possible = false;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    if (possible)
      continue;

    if (s.size() == 1)
      possible = true;
    else if (s.size() == 2 && s[0] == s[1])
      possible = true;
    else if (s.size() == 3 && s[0] == s[2])
      possible = true;
    else if (s.size() == 2) {
      string rev = s;
      swap(rev[0], rev[1]);

      if (freq.count(rev))
        possible = true;

      for (char c = 'a'; c <= 'z'; ++c)
        if (freq.count(rev + c))
          possible = true;
    } else if (s.size() == 3) {
      string rev = s;
      swap(rev[0], rev[2]);

      if (freq.count(rev))
        possible = true;

      string tmp = rev.substr(0, 2);
      if (freq.count(tmp))
        possible = true;
    }

    freq.insert(s);
  }

  cout << ((possible) ? "YES\n" : "NO\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
