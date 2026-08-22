// Source: https://codeforces.com/problemset/problem/546/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 20/08/2026 (DD/MM/YYYY).
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
struct Dinic {
  struct Edge {
    int to, rev;
    ll cap, flow;
  };

  int N;
  vector<vector<Edge>> g;
  vector<int> level, ptr;

  Dinic(int _n) : N(_n), g(_n + 5), level(_n + 5), ptr(_n + 5) {}

  void add_edge(int u, int v, ll cap) {
    g[u].pb({v, (int)g[v].size(), cap, 0});
    g[v].pb({u, (int)g[u].size() - 1, 0, 0});
  }

  bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);

    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &edge : g[u]) {
        if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
          level[edge.to] = level[u] + 1;
          q.push(edge.to);
        }
      }
    }

    return level[t] != -1;
  }

  ll dfs(int v, int t, ll pushed) {
    if (pushed == 0 || v == t)
      return pushed;

    for (int &cid = ptr[v]; cid < g[v].size(); ++cid) {
      auto &edge = g[v][cid];
      int tr = edge.to;

      if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0)
        continue;

      ll tr_pushed = dfs(tr, t, min(pushed, edge.cap - edge.flow));

      if (tr_pushed == 0)
        continue;

      edge.flow += tr_pushed;
      g[tr][edge.rev].flow -= tr_pushed;
      return tr_pushed;
    }

    return 0;
  }

  ll max_flow(int s, int t) {
    ll flow = 0;
    while (bfs(s, t)) {
      fill(ptr.begin(), ptr.end(), 0);
      while (ll pushed = dfs(s, t, 1e18))
        flow += pushed;
    }

    return flow;
  }
};
vector<int> a, b;
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  a.resize(n + 1);
  b.resize(n + 1);
  int sum_a = 0, sum_b = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum_a += a[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    sum_b += b[i];
  }

  if (sum_a != sum_b) {
    cout << "NO";
    return 0;
  }

  int s = 0, t = 2 * n + 1;

  Dinic dinic(2 * n + 2);

  for (int i = 1; i <= n; ++i)
    dinic.add_edge(s, i, a[i]);

  for (int i = 1; i <= n; ++i)
    dinic.add_edge(n + i, t, b[i]);

  for (int i = 1; i <= n; ++i)
    dinic.add_edge(i, n + i, 1e9);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    dinic.add_edge(u, n + v, 1e9);
    dinic.add_edge(v, n + u, 1e9);
  }

  ll flow = dinic.max_flow(s, t);

  if (flow != sum_a) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";
  vector<vector<ll>> ans(n + 1, vector<ll>(n + 1, 0));

  for (int u = 1; u <= n; ++u) {
    for (auto &edge : dinic.g[u]) {
      if (edge.to >= n + 1 && edge.to <= 2 * n) {
        int v = edge.to - n;
        ans[u][v] = edge.flow;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      cout << ans[i][j] << ' ';
    cout << '\n';
  }
}
