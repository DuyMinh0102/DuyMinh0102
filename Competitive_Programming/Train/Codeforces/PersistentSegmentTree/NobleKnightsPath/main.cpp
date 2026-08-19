// Source: https://codeforces.com/problemset/problem/226/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 20/07/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Config
#define pb push_back
#define ll long long
const int N = 100005;

// Variables
struct node {
  int lc, rc, sum;
} t[40 * N];

struct segment {
  int l, r, dir;
};

int n, m, nodecnt = 0;
int a[N], root[N];

vector<int> g[N];
int par[N], d[N], sz[N], heavy[N];
int top[N], pos[N], inv_pos[N];
int pos_cnt = 0;

int upd(int prev, int l, int r, int id, int val) {
  int cur = ++nodecnt;
  t[cur] = t[prev];
  t[cur].sum += val;

  if (l == r)
    return cur;

  int mid = l + ((r - l) >> 1);
  if (id <= mid)
    t[cur].lc = upd(t[cur].lc, l, mid, id, val);
  else
    t[cur].rc = upd(t[cur].rc, mid + 1, r, id, val);

  return cur;
}

int query(int node, int l, int r, int liml, int limr) {
  if (!node || l > limr || r < liml)
    return 0;
  if (liml <= l && r <= limr)
    return t[node].sum;

  int mid = l + ((r - l) >> 1);
  return query(t[node].lc, l, mid, liml, limr) +
         query(t[node].rc, mid + 1, r, liml, limr);
}

int getvalcnt(int year, int y, int total, int l, int r) {
  if (l > r)
    return 0;
  // Fixed variable inconsistency (total vs n)
  int atk = query(root[year], 1, total, l, r) - query(root[y], 1, total, l, r);
  return r - l + 1 - atk;
}

void dfs(int u, int p, int depth) {
  par[u] = p;
  d[u] = depth;
  sz[u] = 1;
  heavy[u] = 0;
  int mxsize = 0;

  for (int v : g[u]) {
    if (v == p)
      continue;

    dfs(v, u, depth + 1);
    sz[u] += sz[v];
    if (sz[v] >= mxsize) {
      mxsize = sz[v];
      heavy[u] = v;
    }
  }
}

void hld(int u, int h) {
  top[u] = h;
  pos[u] = ++pos_cnt;
  inv_pos[pos_cnt] = u;

  if (heavy[u])
    hld(heavy[u], h);

  for (int v : g[u]) {
    if (v == par[u] || v == heavy[u])
      continue;

    hld(v, v); // FIXED: Must be 'v' to denote the start of a new heavy path
  }
}

int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (d[top[u]] < d[top[v]])
      swap(u, v);

    u = par[top[u]];
  }

  return d[u] < d[v] ? u : v;
}

int kth_ances(int u, int k) {
  while (u && k > 0) {
    int len = d[u] - d[top[u]] + 1;
    if (k < len)
      return inv_pos[pos[u] - k];

    k -= len;
    u = par[top[u]];
  }
  return u;
}

int solve(int a, int b, int k, int y, int curr, int n) {
  int LCA = lca(a, b);
  vector<segment> path;

  // FIXED: Robust upward path exclusion handling
  if (d[a] - d[LCA] >= 1) {
    int u = par[a];
    // If LCA is b, stop exactly 1 node before b to exclude it
    int v = (LCA == b) ? kth_ances(a, d[a] - d[LCA] - 1) : LCA;

    if (d[u] >= d[v]) {
      while (top[u] != top[v]) {
        path.pb({pos[top[u]], pos[u], -1});
        u = par[top[u]];
      }
      path.pb({pos[v], pos[u], -1});
    }
  }

  // FIXED: Robust downward path exclusion handling
  if (d[b] - d[LCA] >= 1) {
    // Child of LCA on the path toward b
    int u = kth_ances(b, d[b] - d[LCA] - 1);
    int v = par[b];

    if (d[v] >= d[u]) {
      vector<segment> down;
      while (top[v] != top[u]) {
        down.pb(
            {pos[top[v]], pos[v], 1}); // FIXED: Used pos[v] instead of top[v]
        v = par[top[v]];
      }
      down.pb({pos[u], pos[v], 1});

      reverse(down.begin(), down.end());
      for (auto &seg : down)
        path.pb(seg);
    }
  }

  for (auto &seg : path) {
    int valid = getvalcnt(curr, y, n, seg.l, seg.r);

    if (k <= valid) {
      if (seg.dir == 1) {
        int lo = seg.l, hi = seg.r, ans = seg.r;

        while (lo <= hi) {
          int mid = lo + ((hi - lo) >> 1);
          if (getvalcnt(curr, y, n, seg.l, mid) >= k) {
            ans = mid;
            hi = mid - 1;
          } else
            lo = mid + 1;
        }

        return inv_pos[ans];
      } else {
        int lo = seg.l, hi = seg.r, ans = seg.l;

        while (lo <= hi) {
          int mid = lo + ((hi - lo) >> 1);
          if (getvalcnt(curr, y, n, mid, seg.r) >= k) {
            ans = mid;
            lo = mid + 1;
          } else
            hi = mid - 1;
        }

        return inv_pos[ans];
      }
    }

    k -= valid;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int root_k = 0;
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    if (p == 0)
      root_k = i;
    else {
      g[p].pb(i);
      g[i].pb(p);
    }
  }

  dfs(root_k, 0, 1);
  hld(root_k, root_k);

  root[0] = 0;

  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int c;
      cin >> c;
      root[i] = upd(root[i - 1], 1, n, pos[c], 1);
    } else {
      int a, b, k, y;
      cin >> a >> b >> k >> y;

      root[i] = root[i - 1];

      int ans = solve(a, b, k, y, i, n);
      cout << ans << '\n';
    }
  }
  return 0;
}
