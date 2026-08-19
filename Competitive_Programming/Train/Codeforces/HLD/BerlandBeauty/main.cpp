// Source: https://codeforces.com/problemset/problem/1296/F
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 13/08/2026 (DD/MM/YYYY).
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
const int MX_VAL = 10000000;

// Variables
int N, M;
vector<int> edge2node;

struct Edge {
  int to, id;
};

struct Query {
  int u, v, g;
};
vector<Query> queries;

struct SegmentTree {
  int n;
  vector<int> t, lazy;

  SegmentTree(int _n) : n(_n), t(4 * _n + 5), lazy(4 * _n + 5) {}

  void init(int k, int l, int r) {
    t[k] = 1;
    lazy[k] = 1;
    if (l == r)
      return;
    int mid = l + ((r - l) >> 1);
    init(k << 1, l, mid);
    init(k << 1 | 1, mid + 1, r);
  }

  void push(int k) {
    if (lazy[k] <= 1)
      return;

    t[k << 1] = max(t[k << 1], lazy[k]);
    lazy[k << 1] = max(lazy[k << 1], lazy[k]);

    t[k << 1 | 1] = max(t[k << 1 | 1], lazy[k]);
    lazy[k << 1 | 1] = max(lazy[k << 1 | 1], lazy[k]);

    lazy[k] = 1;
  }

  void update(int k, int l, int r, int liml, int limr, int val) {
    if (r < liml || l > limr)
      return;
    if (liml <= l && r <= limr) {
      t[k] = max(t[k], val);
      lazy[k] = max(lazy[k], val);
      return;
    }
    push(k);

    int mid = l + ((r - l) >> 1);
    if (liml <= mid)
      update(k << 1, l, mid, liml, limr, val);
    if (limr > mid)
      update(k << 1 | 1, mid + 1, r, liml, limr, val);

    t[k] = min(t[k << 1], t[k << 1 | 1]);
  }

  int query(int k, int l, int r, int liml, int limr) {
    if (r < liml || l > limr)
      return MX_VAL;
    if (liml <= l && r <= limr)
      return t[k];

    push(k);
    int mid = l + ((r - l) >> 1);
    return min(query(k << 1, l, mid, liml, limr),
               query(k << 1 | 1, mid + 1, r, liml, limr));
  }
};

struct HLD {
  int n, curpos = 0;
  vector<int> par, sz, head, heavy, depth, pos;
  vector<vector<Edge>> g;
  SegmentTree seg;

  HLD(int _n)
      : n(_n), par(_n + 5), sz(_n + 5), head(_n + 5), heavy(_n + 5, -1),
        pos(_n + 5), depth(_n + 5), seg(_n + 5), g(_n + 5) {}

  void add_edge(int u, int v, int id) {
    g[u].pb({v, id});
    g[v].pb({u, id});
  }

  void dfs(int u, int p = 0, int d = 0) {
    par[u] = p;
    sz[u] = 1;
    depth[u] = d + 1;
    int mx = 0;

    for (const Edge &e : g[u]) {
      int v = e.to;
      if (v == p)
        continue;

      dfs(v, u, d + 1);
      edge2node[e.id] = v;
      sz[u] += sz[v];
      if (sz[v] > mx) {
        mx = sz[v];
        heavy[u] = v;
      }
    }
  }

  void hld(int u, int top) {
    head[u] = top;
    pos[u] = ++curpos;

    if (heavy[u] != -1)
      hld(heavy[u], top);

    for (const Edge &e : g[u]) {
      int v = e.to;
      if (v == par[u] || v == heavy[u])
        continue;

      hld(v, v);
    }
  }

  void init(int root = 1) {
    dfs(root);
    hld(root, root);
    seg.init(1, 1, n);
  }

  void path_upd(int u, int v, int val) {
    while (head[u] != head[v]) {
      if (depth[head[u]] < depth[head[v]])
        swap(u, v);

      seg.update(1, 1, n, pos[head[u]], pos[u], val);
      u = par[head[u]];
    }

    if (depth[u] > depth[v])
      swap(u, v);

    if (pos[u] < pos[v])
      seg.update(1, 1, n, pos[u] + 1, pos[v], val);
  }

  int path_query(int u, int v) {
    int res = 1e9;
    while (head[u] != head[v]) {
      if (depth[head[u]] < depth[head[v]])
        swap(u, v);

      res = min(res, seg.query(1, 1, n, pos[head[u]], pos[u]));

      u = par[head[u]];
    }

    if (depth[u] > depth[v])
      swap(u, v);

    if (pos[u] < pos[v])
      res = min(res, seg.query(1, 1, n, pos[u] + 1, pos[v]));

    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  HLD tree(N);
  edge2node.resize(N + 5);

  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;

    tree.add_edge(u, v, i);
  }

  tree.init();

  cin >> M;
  queries.resize(M);

  for (int i = 0; i < M; ++i) {
    cin >> queries[i].u >> queries[i].v >> queries[i].g;
    tree.path_upd(queries[i].u, queries[i].v, queries[i].g);
  }

  for (int i = 0; i < M; ++i) {
    if (tree.path_query(queries[i].u, queries[i].v) != queries[i].g) {
      cout << -1;
      return 0;
    }
  }

  for (int i = 1; i < N; ++i) {
    int mapped = edge2node[i];
    int val = tree.seg.query(1, 1, N, tree.pos[mapped], tree.pos[mapped]);
    cout << val << ' ';
  }
}
