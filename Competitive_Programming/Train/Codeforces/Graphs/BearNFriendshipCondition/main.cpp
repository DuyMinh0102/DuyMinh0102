// Source: https://codeforces.com/problemset/problem/771/A
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 21/08/2026 (DD/MM/YYYY).
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
const int MAXN = 150005;

// Variables
vector<pair<int, int>> g[MAXN];
bool vis[MAXN];
bool vis_edge[MAXN];
int n, m;
ll e_count = 0, node_count = 0;

void dfs(int u, int p = -1) {
  vis[u] = true;
  ++node_count;

  for (const pair<int, int> &e : g[u]) {
    int v = e.first, id = e.second;
    if (v == p)
      continue;

    if (!vis[v]) {
      vis_edge[id] = true;
      ++e_count;
      dfs(v, u);
    }

    if (!vis_edge[id]) {
      vis_edge[id] = true;
      ++e_count;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    g[u].pb({v, i});
    g[v].pb({u, i});
  }

  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      e_count = 0;
      node_count = 0;
      dfs(i);

      if (e_count != (node_count * (node_count - 1) >> 1)) {
        cout << "NO";
        return 0;
      }
    }
  }

  cout << "YES";
}
