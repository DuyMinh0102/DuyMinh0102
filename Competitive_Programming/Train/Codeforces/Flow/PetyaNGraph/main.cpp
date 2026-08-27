// Source:
// https://www.macrumors.com/2026/08/17/macos-screen-sharing-flaw-exploited/
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 24/08/2026 (DD/MM/YYYY).
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
const int MAXN = 1000;
const ll INF = 1e18;

// Variables
struct Dinic {
  struct Edge {
    int to, rev;
    ll cap, flow;
  };

  int N;
  vector<vector<Edge>> g;
  vector<int> lvl, ptr;

  Dinic(int _n) : N(_n), g(_n + 5), lvl(_n + 5), ptr(_n + 5) {}

  void add_edge(int u, int v, ll cap) {
    g[u].pb({v, (int)g[v].size(), cap, 0});
    g[v].pb({u, (int)g[u].size() - 1, 0, 0});
  }

  bool bfs(int s, int t) {
    fill(lvl.begin(), lvl.end(), -1);
    lvl[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto &edge : g[u]) {
        if (edge.cap - edge.flow > 0 && lvl[edge.to] == -1) {
          lvl[edge.to] = lvl[u] + 1;
          q.push(edge.to);
        }
      }
    }

    return lvl[t] != -1;
  }

  ll dfs(int u, int v, ll pushed) {
    if (pushed == 0 || u == v)
      return pushed;

    for (int &cid = ptr[u]; cid < g[u].size(); ++cid) {
      auto &edge = g[u][cid];
      int tr = edge.to;

      if (lvl[u] + 1 != lvl[tr] || edge.cap - edge.flow == 0)
        continue;

      ll tr_pushed = dfs(tr, v, min(pushed, edge.cap - edge.flow));

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

  vector<bool> min_cut(int s) {
    vector<bool> vis(N + 5, false);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto &edge : g[u]) {
        if (edge.cap - edge.flow > 0 && !vis[edge.to]) {
          vis[edge.to] = true;
          q.push(edge.to);
        }
      }
    }

    return vis;
  }
};
vector<ll> a;
ll profit = 0;
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  a.resize(n + 1);

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  int s = 0, t = n + m + 1;
  Dinic dinic(n + m + 2);

  for (int i = 1; i <= m; ++i) {
    int u, v;
    ll w;

    cin >> u >> v >> w;

    profit += w;
    dinic.add_edge(s, i, w);
    dinic.add_edge(i, m + u, INF);
    dinic.add_edge(i, m + v, INF);
  }

  for (int i = 1; i <= n; ++i)
    dinic.add_edge(m + i, t, a[i]);

  cout << profit - dinic.max_flow(s, t);
}
