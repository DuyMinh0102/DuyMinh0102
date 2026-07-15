// Source: https://codeforces.com/contest/1511/problem/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 11/07/2026 (DD/MM/YYYY).
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
int n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  string rep = "";

  for (int i = 0; i < k; ++i) {
    rep += (char)(i + 'a');

    for (int j = i + 1; j < k; ++j) {
      rep += (char)(i + 'a');
      rep += (char)(j + 'a');
    }
  }

  for (int i = 0; i < n; ++i)
    cout << rep[i % (int)rep.size()];
}
