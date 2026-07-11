// Source: https://codeforces.com/contest/271/problem/D
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
const int N = 1500 * 1500 / 2 + 5;

// Variables
int k, trie[N][26];
string s, bad;
int node_cnt = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> bad >> k;
  int n = s.size();
  int total = 0;

  for (int i = 0; i < n; ++i) {
    int node = 0, cnt = 0;

    for (int j = i; j < n; ++j) {
      int id = s[j] - 'a';

      if (bad[id] == '0')
        ++cnt;
      if (cnt > k)
        break;

      if (trie[node][id] == 0) {
        trie[node][id] = ++node_cnt;
        ++total;
      }

      node = trie[node][id];
    }
  }

  cout << total;
}
