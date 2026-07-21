// Source:
// Status:
/*
Note: a grid of size R x C, the farm plot at i-th row and j-th col is denoted as
(i, j). Each (i, j) has an elevation of L_ij (pairwise distinct), and a type
P_ij. When a flood of height H occurs, any plot with elevation <= H will be
flooded. On a flooded plot, you can go to any shared-edge plot if it's also
flooded.

2 type of queries:
1 X Y P: changes the type of (X, Y) to P
2 X Y L: when a flood of height L occurs, count the amount of different types
P_ij the flooded region containing plot (X, Y), if (X,Y) is not flooded when
flood L occurs, output 0.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 21/07/2026 (DD/MM/YYYY).
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
const int N = 50000;
const int lg = 17;

// Variables
int r, c, q, timer = 0;

int elevation[N + 5];
int type[N + 5];

int lift[N + 5][lg], in[N + 5], ou[N + 5], flat[N + 5], node_flat[N + 5],
    par[N + 5], ans[2 * N + 5];
int freq[N + 5], distinct = 0, cur_type[N + 5];

vector<int> g[N + 5];

struct Update {
  int pos, oldval, newval;
};

struct Query {
  int l, r, t, id, bl, br;

  bool operator<(const Query &other) const {
    if (bl != other.bl)
      return bl < other.bl;
    if (br != other.br)
      return (bl & 1) ? br < other.br : br > other.br;

    return (br & 1) ? t < other.t : t > other.t;
  }
};

struct Plot {
  int id, elev, r, c;
  bool operator<(const Plot &other) const { return elev < other.elev; }
};

int getid(int _r, int _c) { return (_r - 1) * c + _c; }

int findset(int v) { return (v == par[v]) ? v : par[v] = findset(par[v]); }

vector<Update> upds;
vector<Query> quers;
vector<Plot> plots;

void dfs(int u, int p) {
  lift[u][0] = p;
  for (int i = 1; i < lg; ++i)
    lift[u][i] = lift[lift[u][i - 1]][i - 1];

  in[u] = ++timer;
  flat[timer] = type[u];
  node_flat[u] = timer;

  for (int v : g[u]) {
    if (v == p)
      continue;

    dfs(v, u);
  }
  ou[u] = timer;
}

void add(int v) {
  if (freq[v] == 0)
    ++distinct;
  ++freq[v];
}

void rem(int v) {
  --freq[v];
  if (freq[v] == 0)
    --distinct;
}

void update(int id, int l, int r) {
  int p = upds[id].pos;
  if (l <= p && p <= r) {
    rem(cur_type[p]);
    add(upds[id].newval);
  }

  swap(cur_type[p], upds[id].newval);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c >> q;

  int n = r * c;

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      int id = getid(i, j);
      cin >> elevation[id];
      plots.pb({id, elevation[id], i, j});
      par[id] = id;
    }
  }

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      cin >> type[getid(i, j)];
    }
  }

  sort(plots.begin(), plots.end());

  int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

  int root = plots.back().id;

  for (const Plot &plot : plots) {
    int u = plot.id;
    for (int i = 0; i < 4; ++i) {
      int x = plot.r + dr[i], y = plot.c + dc[i];

      if (x >= 1 && x <= r && y >= 1 && y <= c) {
        int v = getid(x, y);

        if (elevation[v] < elevation[u]) {
          int rootv = findset(v);
          if (rootv != u) {
            g[u].pb(rootv);
            par[rootv] = u;
          }
        }
      }
    }
  }

  elevation[0] = 2e9;
  dfs(root, 0);

  for (int i = 1; i <= n; ++i)
    cur_type[i] = flat[i];

  vector<int> tracking(cur_type, cur_type + n + 1);

  upds.pb({0, 0, 0});

  int B = pow(n, 0.666) + 1;

  int qcnt = 0;
  while (q--) {
    int qt;
    cin >> qt;

    if (qt == 1) {
      int x, y, p;
      cin >> x >> y >> p;

      int u = getid(y, x);
      int pos = node_flat[u];

      upds.pb({pos, tracking[pos], p});
      tracking[pos] = p;
    } else {
      int x, y;
      ll l;
      cin >> x >> y >> l;

      int u = getid(y, x);
      if (elevation[u] > l) {
        ans[qcnt++] = 0;
        continue;
      }

      for (int k = lg - 1; k >= 0; --k) {
        if (lift[u][k] != 0 && elevation[lift[u][k]] <= l)
          u = lift[u][k];
      }

      quers.pb(
          {in[u], ou[u], (int)upds.size() - 1, qcnt++, in[u] / B, ou[u] / B});
    }
  }

  sort(quers.begin(), quers.end());

  int l = 1, r = 0, t = 0;
  for (const Query &query : quers) {
    while (t < query.t)
      update(++t, l, r);
    while (t > query.t)
      update(t--, l, r);

    while (l > query.l)
      add(cur_type[--l]);
    while (r < query.r)
      add(cur_type[++r]);

    while (l < query.l)
      rem(cur_type[l++]);
    while (r > query.r)
      rem(cur_type[r--]);

    ans[query.id] = distinct;
  }

  for (int i = 0; i < qcnt; ++i)
    cout << ans[i] << '\n';
}
