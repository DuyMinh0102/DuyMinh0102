// Source: https://codeforces.com/contest/1017/problem/G
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
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
int N, Q;

struct Node {
  int sum, maxsuf;
};

Node merge(const Node &l, const Node &r) {
  Node res;
  res.sum = l.sum + r.sum;
  res.maxsuf = max(r.maxsuf, l.maxsuf + r.sum);

  return res;
};

struct SegTree {
  int n;
  vector<Node> t;
  vector<bool> lazy;

  SegTree(int _n = 0) : n(_n), t(4 * _n), lazy(4 * _n, false) {}

  void build(int k, int l, int r) {
    if (l == r) {
      t[k] = {-1, -1};
      return;
    }

    int mid = l + ((r - l) >> 1);
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);

    t[k] = merge(t[k << 1], t[k << 1 | 1]);
  }

  void push(int k, int l, int r) {
    if (!lazy[k])
      return;

    int mid = l + ((r - l) >> 1);

    int lenl = mid - l + 1;
    t[k << 1] = {-lenl, -1};
    lazy[k << 1] = true;

    int lenr = r - mid;
    t[k << 1 | 1] = {-lenr, -1};
    lazy[k << 1 | 1] = true;

    lazy[k] = false;
  }

  void range(int k, int l, int r, int liml, int limr) {
    if (limr < l || r < liml)
      return;
    if (liml <= l && r <= limr) {
      t[k] = {-(r - l + 1), -1};
      lazy[k] = true;
      return;
    }

    push(k, l, r);
    int mid = l + ((r - l) >> 1);
    range(k << 1, l, mid, liml, limr);
    range(k << 1 | 1, mid + 1, r, liml, limr);
    t[k] = merge(t[k << 1], t[k << 1 | 1]);
  }

  void point(int k, int l, int r, int id, int diff) {
    if (l == r) {
      t[k].sum += diff;
      t[k].maxsuf += diff;
      return;
    }

    push(k, l, r);
    int mid = l + ((r - l) >> 1);
    if (id <= mid)
      point(k << 1, l, mid, id, diff);
    else
      point(k << 1 | 1, mid + 1, r, id, diff);

    t[k] = merge(t[k << 1], t[k << 1 | 1]);
  }

  void point_set(int k, int l, int r, int id, int val) {
    if (l == r) {
      t[k].sum = val;
      t[k].maxsuf = val;
      return;
    }

    push(k, l, r);

    int mid = l + ((r - l) >> 1);
    if (id <= mid)
      point_set(k << 1, l, mid, id, val);
    else
      point_set(k << 1 | 1, mid + 1, r, id, val);

    t[k] = merge(t[k << 1], t[k << 1 | 1]);
  }

  Node query(int k, int l, int r, int liml, int limr) {
    if (liml <= l && r <= limr)
      return t[k];

    push(k, l, r);
    int mid = l + ((r - l) >> 1);
    if (limr <= mid)
      return query(k << 1, l, mid, liml, limr);
    if (liml > mid)
      return query(k << 1 | 1, mid + 1, r, liml, limr);

    return merge(query(k << 1, l, mid, liml, limr),
                 query(k << 1 | 1, mid + 1, r, liml, limr));
  }

  int query_point(int k, int l, int r, int id) {
    if (l == r)
      return t[k].sum;

    push(k, l, r);
    int mid = l + ((r - l) >> 1);
    if (id <= mid)
      return query_point(k << 1, l, mid, id);

    return query_point(k << 1 | 1, mid + 1, r, id);
  }
};

struct HLD {
  int n, curpos;
  vector<vector<int>> g;
  vector<int> par, depth, heavy, head, pos, sz;
  SegTree seg;

  HLD(int _n)
      : n(_n), curpos(0), g(_n), par(_n), depth(_n), heavy(_n, -1), pos(_n),
        sz(_n), head(_n), seg(_n) {}

  void add_edge(int u, int v) {
    g[u].pb(v);
    g[v].pb(u);
  }

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
    head[u] = top;
    pos[u] = ++curpos;
    if (heavy[u] != -1)
      hld(heavy[u], top);

    for (int v : g[u]) {
      if (v == par[u] || v == heavy[u])
        continue;

      hld(v, v);
    }
  }

  Node query(int u) {
    vector<Node> blocks;

    while (u > 0) {
      int h = head[u];
      blocks.pb(seg.query(1, 1, n, pos[h], pos[u]));
      u = par[h];
    }
    Node res = blocks.back();
    for (int i = (int)blocks.size() - 2; i >= 0; --i)
      res = merge(res, blocks[i]);
    return res;
  }

  void add_black(int u) { seg.point(1, 1, n, pos[u], 1); }

  void clear_subtr(int u) {
    Node res = query(u);

    int old = seg.query_point(1, 1, n, pos[u]);
    int m = res.maxsuf - old;

    seg.range(1, 1, n, pos[u], pos[u] + sz[u] - 1);
    seg.point_set(1, 1, n, pos[u], -1 - m);
  }

  bool is_black(int u) { return query(u).maxsuf >= 0; }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> Q;

  HLD hld(N + 5);

  for (int i = 2; i <= N; ++i) {
    int v;
    cin >> v;

    hld.add_edge(i, v);
  }

  hld.dfs(1);
  hld.hld(1, 1);
  hld.seg.build(1, 1, hld.n);

  while (Q--) {
    int t, id;

    cin >> t >> id;

    if (t == 1)
      hld.add_black(id);
    else if (t == 2)
      hld.clear_subtr(id);
    else {
      if (hld.is_black(id))
        cout << "black\n";
      else
        cout << "white\n";
    }
  }
}
