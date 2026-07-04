// Source: https://marisaoj.com/problem/239
// Status: Unsolved
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
const int N = 1000005;

// Variables
int n, nodeCNT = 1;
int trie[N][26];
ll sz[N];
bool isEnd[N];
ll mx = 0;

void addString(string &s) {
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
  for (int i = 0; i < 26; ++i) {
    if (trie[u][i]) {
      int v = trie[u][i];
      mx = max(sz[v] * (d + 1), mx);

      dfs(v, d + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    addString(s);
  }

  dfs(0, 0);

  cout << mx;
}
