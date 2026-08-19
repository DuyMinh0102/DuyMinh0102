// Source: https://codeforces.com/problemset/problem/208/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 14/08/2026 (DD/MM/YYYY).
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
const int MAXN = 100005;

// Variables
int N, M, timer = 0;
vector<int> g[MAXN], depth_nodes[MAXN];
int up[MAXN][20], tin[MAXN], tout[MAXN], depth[MAXN];

void dfs(int u, int p = 0, int d = 0) {
  depth[u] = d;
  tin[u] = ++timer;
  depth_nodes[d].pb(tin[u]);

  up[u][0] = p;
  for (int i = 1; i < 20; ++i)
    up[u][i] = up[up[u][i - 1]][i - 1];

  for (int v : g[u]) {
    if (v == p)
      continue;

    dfs(v, u, d + 1);
  }

  tout[u] = timer;
}

int get_ances(int u, int p) {
  for (int i = 0; i < 20; ++i) {
    if ((p >> i) & 1)
      u = up[u][i];
  }

  return u;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int x;
    cin >> x;

    g[x].pb(i);
  }

  dfs(0);

  cin >> M;
  for (int i = 0; i < M; ++i) {
    int v, p;
    cin >> v >> p;

    int z = get_ances(v, p);

    if (z == 0)
      cout << 0 << ' ';
    else {
      int target = depth[v];

      auto a = lower_bound(depth_nodes[target].begin(),
                           depth_nodes[target].end(), tin[z]);
      auto b = upper_bound(depth_nodes[target].begin(),
                           depth_nodes[target].end(), tout[z]);

      cout << (int)(distance(a, b) - 1) << ' ';
    }
  }
}
