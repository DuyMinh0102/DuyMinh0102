// Source: https://codeforces.com/contest/701/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 02/07/2026 (DD/MM/YYYY).
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
int n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;

  unordered_set<char> types(s.begin(), s.end());
  int required = types.size();

  unordered_map<char, int> cnt;
  int l = 0, mn = n, cur = 0;

  for (int r = 0; r < n; ++r) {
    char c = s[r];

    if (cnt[c] == 0)
      ++cur;

    ++cnt[c];

    while (cur == required) {
      mn = min(mn, r - l + 1);

      char l_c = s[l];
      --cnt[l_c];

      if (cnt[l_c] == 0)
        --cur;

      ++l;
    }
  }

  cout << mn;
}
