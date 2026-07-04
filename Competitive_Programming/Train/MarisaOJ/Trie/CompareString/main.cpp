// Source: https://marisaoj.com/problem/244
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 29/06/2026 (DD/MM/YYYY).
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
#define file ""
const int N = 1000005;

// Variables
int n, trie[N][26], nodeCNT = 1;
bool isEnd[N];
ll sz[N], ans = 0;

void insert(string &s) {
  int u = 0;
  ++sz[u];
  for (char c : s) {
    int v = c - 'a';
    if (trie[u][v] == 0)
      trie[u][v] = ++nodeCNT;

    u = trie[u][v];
    ++sz[u];
  }
  isEnd[u] = true;
}

void dfs(int u, int d) {
  ll sumsz = 0, sumsz_sq = 0;
  for (int i = 0; i < 26; ++i) {
    if (trie[u][i]) {
      int v = trie[u][i];

      sumsz += sz[v];
      sumsz_sq += sz[v] * sz[v];

      dfs(v, d + 1);
    }
  }

  ll pairs = (sumsz * sumsz - sumsz_sq) / 2;

  ans += pairs * (d + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    insert(s);
  }

  dfs(0, 0);

  cout << ans;
  return 0;
}
