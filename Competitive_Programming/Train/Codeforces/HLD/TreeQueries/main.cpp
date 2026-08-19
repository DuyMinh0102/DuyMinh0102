// Source: https://codeforces.com/contest/1254/problem/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 11/08/2026 (DD/MM/YYYY).
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
const ll MOD = 998244353;

// Variables
int N, Q;
ll binpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = (res * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }

  return res;
}

ll modInver(ll n) { return binpow(n, MOD - 2); }

struct Node {
  ll sum_heavy, sum_direct;
};

Node merge(const Node &l, const Node &r) {
  return {(l.sum_heavy + r.sum_heavy) % MOD,
          (l.sum_direct + r.sum_direct) % MOD};
}

struct SegTree {
  int n;
  vector<Node> t;

  SegTree(int _n = 0) : n(_n), t(4 * n + 5, {0, 0}) {}

  void point_add(int k, int l, int r, int id, ll d_heavy, ll d_direct) {
    if (l == r) {
      t[k].sum_heavy = (t[k].sum_heavy + d_heavy) % MOD;
      t[k].sum_direct = (t[k].sum_direct + d_direct) % MOD;
      return;
    }

    int mid = l + ((r - l) >> 1);
    if (id <= mid)
      point_add(k << 1, l, mid, id, d_heavy, d_direct);
    else
      point_add(k << 1 | 1, mid + 1, r, id, d_heavy, d_direct);

    t[k] = merge(t[k << 1], t[k << 1 | 1]);
  }

  Node query(int k, int l, int r, int liml, int limr) {
    if (r < liml || l > limr)
      return {0, 0};
    if (liml <= l && r <= limr)
      return t[k];

    int mid = l + ((r - l) >> 1);
    return merge(query(k << 1, l, mid, liml, limr),
                 query(k << 1 | 1, mid + 1, r, liml, limr));
  }
};

struct HLD {
  int n, curpos;
  vector<vector<int>> g;
  vector<int> par, heavy, depth, head, pos;
  vector<ll> sz, lazy;
  SegTree seg;

  ll global_s = 0, invN;

  HLD(int _n)
      : n(_n), g(_n + 1), par(_n + 1), depth(_n + 1), heavy(_n + 1, 0),
        pos(_n + 1), sz(_n + 1), head(_n + 1), lazy(_n + 1, 0), seg(_n),
        curpos(0) {
    invN = modInver(n);
  }

  void add_edge(int u, int v) {
    g[v].pb(u);
    g[u].pb(v);
  }

  void dfs(int u, int p = 0, int d = 0) {
    par[u] = p;
    depth[u] = d;
    sz[u] = 1;
    ll mx = 0;

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

    if (heavy[u] != 0)
      hld(heavy[u], top);

    for (int v : g[u]) {
      if (v == par[u] || v == heavy[u])
        continue;

      hld(v, v);
    }
  }

  void init(int root = 1) {
    dfs(root);
    hld(root, root);
  }

  void add_op(int u, ll d) {
    d %= MOD;
    global_s = (global_s + d * sz[u]) % MOD;
    lazy[u] = (lazy[u] + d) % MOD;

    ll add_heavy = heavy[u] ? (d * sz[heavy[u]]) % MOD : 0,
       add_direct = (d * (n - sz[u])) % MOD;

    seg.point_add(1, 1, n, pos[u], add_heavy, add_direct);
  }

  ll query(int u) {
    ll path = 0, path_sub = 0;
    int curr = u;

    while (curr > 0) {
      int h = head[curr];

      Node q = seg.query(1, 1, n, pos[h], pos[curr]);
      path = (path + q.sum_direct) % MOD;

      if (pos[curr] > pos[h]) {
        Node q_heavy = seg.query(1, 1, n, pos[h], pos[curr] - 1);
        path_sub = (path_sub + q_heavy.sum_heavy) % MOD;
      }

      if (par[h] > 0)
        path_sub = (path_sub + lazy[par[h]] * sz[h]) % MOD;

      curr = par[h];
    }

    ll ans = (global_s + path - path_sub) % MOD;
    if (ans < 0)
      ans += MOD;

    return (ans * invN) % MOD;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> Q;

  HLD tree(N);

  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;

    tree.add_edge(u, v);
  }

  tree.init(1);

  while (Q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int v;
      ll d;
      cin >> v >> d;

      tree.add_op(v, d);
    } else {
      int v;
      cin >> v;

      cout << tree.query(v) << '\n';
    }
  }
}
