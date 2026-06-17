// Source:
// Status: Unsolved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 17/06/2026 (DD/MM/YYYY).
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
const int N = 200005, lg = 18;

// Variables
int n, q, t, up[N][lg], d[N], d2[N];
int mx = 0, mx_id = 0, a, b;
vector<int> g[N];

void dfs(int u, int p) {
  d[u] = d[p] + 1;
  up[u][0] = p;
  if (d[u] > mx) {
    mx = d[u];
    mx_id = u;
  }

  for (int i = 1; i < lg; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }

  for (int v : g[u]) {
    if (v == p)
      continue;

    dfs(v, u);
  }
}

void dfs2(int u, int p) {
  d2[u] = d2[p] + 1;
  if (d2[u] > mx) {
    mx = d2[u];
    mx_id = u;
  }

  for (int v : g[u]) {
    if (v == p)
      continue;

    dfs2(v, u);
  }
}

int ancestor(int u, int k) {
  for (int j = lg - 1; j >= 0; --j) {
    if (k & (1 << j))
      u = up[u][j];
  }
  return u;
}

int LCA(int u, int v) {
  if (d[u] < d[v])
    swap(u, v);

  int diff = d[u] - d[v];
  for (int i = 0; (1 << i) <= diff; ++i) {
    if (diff >> i & 1)
      u = up[u][i];
  }

  if (u == v)
    return v;

  for (int i = lg - 1; i >= 0; --i) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0];
}

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i)
    g[i].clear();

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }

  d[0] = d2[0] = -1;
  mx = -1;
  dfs(1, 0);
  a = mx_id;
  mx = -1;
  dfs2(a, 0);
  b = mx_id;

  while (q--) {
    int v, query;
    cin >> v >> query;

    if (d[v] >= query) {
      cout << ancestor(v, query) << '\n';
    } else {

      int dist_a = d[a] + d[v] - 2 * d[LCA(a, v)],
          dist_b = d[b] + d[v] - 2 * d[LCA(b, v)];

      if (max(dist_a, dist_b) < query)
        cout << 0 << '\n';
      else {
        if (dist_a >= query)
          cout << ancestor(a, dist_a - query) << '\n';
        else
          cout << ancestor(b, dist_b - query) << '\n';
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    solve();
  }
}
