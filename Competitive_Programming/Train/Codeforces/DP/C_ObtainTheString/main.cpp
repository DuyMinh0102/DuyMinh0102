// Source: https://codeforces.com/contest/1296/problem/C
// Status: Solved
/*
Note: Given two strings s and t. You have an empty string z. You can append any
subsequence of any length of s to z in one operation. Find the minimum amount of
operations needed so z = t. If cannot: output -1

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 11/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';
#define vt vector

// Config
#define pb push_back
#define ll long long

// Variables
int query;
string s, t;

void solve() {
  cin >> s >> t;
  string z = "";
  int n = s.size();

  vt<vt<int>> nxt(n + 1, vt<int>(26, -1));

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][s[i] - 'a'] = i;
  }

  int pos = 0, res = 1;

  for (char c : t) {
    int char_id = c - 'a';

    if (nxt[0][char_id] == -1) {
      cout << -1 << '\n';
      return;
    }

    if (pos == n || nxt[pos][char_id] == -1) {
      ++res;
      pos = 0;
    }

    pos = nxt[pos][char_id] + 1;
  }

  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> query;

  while (query--) {
    solve();
  }
}
