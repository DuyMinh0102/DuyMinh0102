// Source: https://codeforces.com/contest/448/problem/B
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
string s, t;
int freq[26][2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> t;
  int n = (int)s.size(), m = (int)t.size();

  for (int i = 0; i < m; ++i)
    ++freq[t[i] - 'a'][1];

  for (int i = 0; i < n; ++i)
    ++freq[s[i] - 'a'][0];

  for (int i = 0; i < 26; ++i)
    if (freq[i][1] > freq[i][0]) {
      cout << "need tree";
      return 0;
    }

  if (n == m) {
    cout << "array";
    return 0;
  }

  int i = 0, j = 0;

  while (i < n && j < m) {
    if (s[i] == t[j])
      ++j;
    ++i;
  }

  if (j == m) {
    cout << "automaton";
    return 0;
  }

  cout << "both";
}
