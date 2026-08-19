// Source: https://codeforces.com/problemset/problem/191/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 12/03/2026 (DD/MM/YYYY).
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
int N, k;

struct SegmentTree {
  int n;
  vector<ll> t, lazy;

  SegmentTree(int _n) : n(_n), t(4 * _n + 5, 0), lazy(4 * n + 5, 0) {}

  void push(int k) {
    if (!lazy[k])
      return;

    lazy[k << 1] += lazy[k];
    t[k << 1] += lazy[k];
    lazy[k << 1 | 1] += lazy[k];
    t[k << 1 | 1] += lazy[k];

    lazy[k] = 0;
  }

  void range_upd(int k, int l, int r, int liml, int limr) {
    if (l > limr || r < liml)
      return;
    if (liml <= l && r <= limr) {
      ++t[k];
      ++lazy[k];
      return;
    }

    push(k);
    int mid = l + ((r - l) >> 1);
    range_upd(k << 1, l, mid, liml, limr);
    range_upd(k << 1 | 1, mid + 1, r, liml, limr);
  }

  int get(int k, int l, int r, int pos) {
    if (l == r)
      return t[k];

    push(k);
    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
      return get(k << 1, l, mid, pos);

    return get(k << 1 | 1, mid + 1, r, pos);
  }
};

struct HLD {
  int n, curpos;
  vector<vector<int>> g;
  vector<int> head, heavy, sz, par, depth, pos;
  SegmentTree seg;

  HLD(int _n)
      : n(_n), g(_n + 5), head(_n + 5), heavy(_n + 5, -1), depth(_n + 5),
        sz(_n + 5), seg(_n), pos(_n + 5), par(_n + 5), curpos(0) {}

  void dfs(int u, int p = 0, int d = 0) {
    par[u] = p;
    depth[u] = d;
    sz[u] = 1;
    int mx = 0;

    for (int v : g[u]) {
      if (v == p)
        continue;

      dfs(v, u, d + 1);
      sz[u] += sz[v];

      if (sz[v] > mx) {
        mx = sz[v];
        heavy[u] = v;
      }
    }
  }

  void hld(int u, int top) {
    pos[u] = ++curpos;
    head[u] = top;

    if (heavy[u] != -1)
      hld(heavy[u], top);

    for (int v : g[u]) {
      if (v == par[u] || v == heavy[u])
        continue;

      hld(v, v);
    }
  }

  void add_edge(int u, int v) {
    g[u].pb(v);
    g[v].pb(u);
  }

  void init(int root = 1) {
    dfs(root);
    hld(root, root);
  }

  void range(int u, int v) {
    while (head[v] != head[u]) {
      if (depth[head[u]] < depth[head[v]])
        swap(u, v);

      seg.range_upd(1, 1, n, pos[head[u]], pos[u]);

      u = par[head[u]];
    }

    if (depth[u] > depth[v])
      swap(u, v);

    seg.range_upd(1, 1, n, pos[u] + 1, pos[v]);
  }

  int get(int u) { return seg.get(1, 1, n, pos[u]); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  HLD tree(N);

  vector<pair<int, int>> edges;

  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;

    tree.add_edge(u, v);
    edges.pb({u, v});
  }

  tree.init();

  cin >> k;

  while (k--) {
    int a, b;
    cin >> a >> b;

    tree.range(a, b);
  }

  for (int i = 0; i < N - 1; ++i) {
    int u = edges[i].first, v = edges[i].second;

    cout << tree.get(tree.depth[u] > tree.depth[v] ? u : v) << ' ';
  }
}
