// Source: No source
// Status: Unsolved
/*
Note: Given an undirected graph with N vetices and M edges. For each edge,
determine if it belongs to all MST of the graph.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 18/05/2026 (DD/MM/YYYY).
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
const int N = 200005;

// Variables
int n, m, timer = 0;
vector<pair<int, int>> g[N];
vector<int> par(N), low(N, 0), disc(N, 0);
vector<bool> br(N, false);
struct edge{
  int u, v, id;
  ll w;
  edge(){}

  edge(int _u, int _v, ll _w, int _id): u(_u), v(_v), w(_w), id(_id) {}

  bool operator<(const edge& other){
    return w < other.w;
  }
};
vector<edge> e;

int findset(int u){ return (u == par[u]) ? u : par[u] = findset(par[u]); }

bool uni(int u, int v){
  u = findset(u); v = findset(v);

  if (u == v) return false;
  par[v] = u;
  return true;
}

void dfs(int u, int p_id){
  low[u] = disc[u] = ++timer;

  for (pair<int, int> uv : g[u]){
    int v = uv.first, id = uv.second;
    if (id != p_id){
      if (disc[v] == 0){
        dfs(v, id);
        low[u] = min (low[u], low[v]);

        if (low[v] > disc[u]){
          br[id] = true;
        }
      }
      else{
        low[u] = min(low[u], disc[v]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("allmst.inp", "r", stdin);
  freopen("allmst.out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) par[i] = i;

  for (int i = 0; i < m; ++i){
    int u, v; ll w;
    cin >> u >> v >> w;

    e.pb(edge(u, v, w, i));
  }
  sort(e.begin(), e.end());

  int i = 0;
  while(i < m){
    int st = i;
    while (i < m && e[i].w == e[st].w){
      ++i;
    }

    vector<int> active;
      
    for (int j = st; j < i; ++j){
      int u = findset(e[j].u), v = findset(e[j].v);

      if (u == v) continue;

      g[u].pb({v, e[j].id});
      g[v].pb({u, e[j].id});

      active.pb(u);
      active.pb(v);
    }

    for (int i : active){
      if (disc[i] == 0) dfs(i, -1);
    }

    for(int j = st; j < i; ++j){
      int u = findset(e[j].u), v = findset(e[j].v);

      uni(u, v);
    }

    for (int i : active){
      g[i].clear();
      disc[i] = low[i] = 0;
    }
    timer = 0;
  }

  for (int i = 0; i < m; ++i){
    if (br[i]) cout << "Yes ";
    else cout << "No ";
  }
}
