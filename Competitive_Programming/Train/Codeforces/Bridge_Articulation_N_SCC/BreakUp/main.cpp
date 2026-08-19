// Source: https://codeforces.com/contest/700/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 04/08/2026 (DD/MM/YYYY).
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
const int N = 1000;
const ll INF = 4e18;

// Variables
struct edge {
  int v, id;
  ll w;

  edge() {}

  edge(int _v, ll _w, int _id) : v(_v), w(_w), id(_id) {}
};

struct edge_inp {
  int u, v;
  ll w;
};

int n, m, s, t, timer = 0, disabled_edge = -1;
vector<edge> g[N + 5];
vector<edge_inp> edges;

vector<int> tin, low;
vector<int> par, par_edge;
vector<bool> vis;
vector<bool> is_bridge;

void dfs(int u) {
  vis[u] = true;

  for (auto &e : g[u]) {
    if (!vis[e.v]) {
      par[e.v] = u;
      par_edge[e.v] = e.id;
      dfs(e.v);
    }
  }
}

void dfs_tarjan(int u, int p_edge) {
  vis[u] = true;
  tin[u] = low[u] = ++timer;

  for (auto &e : g[u]) {
    int v = e.v, id = e.id;
    if (id == disabled_edge)
      continue;
    if (id == p_edge)
      continue;

    if (vis[v])
      low[u] = min(low[u], tin[v]);
    else {
      par[v] = u;
      par_edge[v] = id;

      dfs_tarjan(v, id);

      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u])
        is_bridge[id] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> s >> t;

  edges.resize(m + 1);

  for (int i = 1; i <= m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    edges[i] = {u, v, w};

    if (u == v)
      continue;

    g[u].pb(edge(v, w, i));
    g[v].pb(edge(u, w, i));
  }

  vis.assign(n + 1, false);
  par.assign(n + 1, -1);
  par_edge.assign(n + 1, -1);

  dfs(s);

  if (!vis[t]) {
    cout << 0 << '\n';
    cout << 0 << '\n';
    return 0;
  }

  vector<int> path;

  int curr = t;
  while (curr != s) {
    int e_id = par_edge[curr];

    path.pb(e_id);
    curr = par[curr];
  }

  ll cost = INF;
  vector<int> ans;

  for (int e : path) {
    disabled_edge = e;

    vis.assign(n + 1, false);
    par.assign(n + 1, -1);
    par_edge.assign(n + 1, -1);
    tin.assign(n + 1, 0);
    low.assign(n + 1, 0);
    is_bridge.assign(m + 1, false);
    timer = 0;

    dfs_tarjan(s, -1);

    if (!vis[t]) {
      if (edges[e].w < cost) {
        cost = edges[e].w;
        ans = {e};
      }
    } else {
      int node = t;
      while (node != s) {
        int cur_id = par_edge[node];

        if (is_bridge[cur_id]) {
          ll cur_cost = edges[e].w + edges[cur_id].w;
          if (cur_cost < cost) {
            cost = cur_cost;
            ans = {e, cur_id};
          }
        }

        node = par[node];
      }
    }
  }

  if (cost == INF)
    cout << -1;
  else {
    cout << cost << '\n';
    cout << ans.size() << '\n';
    for (int i : ans)
      cout << i << ' ';
  }
}
