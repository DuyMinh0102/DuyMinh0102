// Source: https://codeforces.com/contest/707/problem/D
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
const int N = 100005;

// Variables
int n, m, q;
bool state[N];

struct Node {
  int sum, le, ri;
  bool invert = false;
};
Node t[200 * N];
vector<int> root(N);
int nodecnt = 0, rootid = 0;

int clone(int prev) {
  int id = ++nodecnt;
  t[id] = t[prev];
  return id;
}

void pushdown(int id, int l, int r) {
  if (!t[id].invert)
    return;

  int mid = l + ((r - l) >> 1);
  t[id].le = clone(t[id].le);
  t[t[id].le].invert ^= 1;
  t[t[id].le].sum = (mid - l + 1) - t[t[id].le].sum;

  t[id].ri = clone(t[id].ri);
  t[t[id].ri].invert ^= 1;
  t[t[id].ri].sum = (r - mid) - t[t[id].ri].sum;

  t[id].invert = false;
}

int build(int l, int r) {
  int id = ++nodecnt;
  t[id] = {0, 0, 0, false};
  if (l == r)
    return id;

  int mid = l + ((r - l) >> 1);
  t[id].le = build(l, mid);
  t[id].ri = build(mid + 1, r);
  return id;
}

int get(int id, int l, int r, int pos, bool inv) {
  if (l == r)
    return t[id].sum ^ inv;

  inv ^= t[id].invert;
  int mid = l + ((r - l) >> 1);

  if (pos <= mid)
    return get(t[id].le, l, mid, pos, inv);
  else
    return get(t[id].ri, mid + 1, r, pos, inv);
}

int upd_p(int prev, int l, int r, int pos, int val) {
  int id = clone(prev);
  if (l == r) {
    t[id].sum = val;
    t[id].invert = false;
    return id;
  }

  pushdown(id, l, r);
  int mid = l + ((r - l) >> 1);

  if (pos <= mid)
    t[id].le = upd_p(t[id].le, l, mid, pos, val);
  else
    t[id].ri = upd_p(t[id].ri, mid + 1, r, pos, val);

  t[id].sum = t[t[id].le].sum + t[t[id].ri].sum;
  return id;
}

int upd_range(int prev, int l, int r, int liml, int limr) {
  int id = clone(prev);
  if (liml <= l && r <= limr) {
    t[id].invert ^= 1;
    t[id].sum = (r - l + 1) - t[id].sum;
    return id;
  }

  pushdown(id, l, r);
  int mid = l + ((r - l) >> 1);
  if (liml <= mid)
    t[id].le = upd_range(t[id].le, l, mid, liml, limr);
  if (limr > mid)
    t[id].ri = upd_range(t[id].ri, mid + 1, r, liml, limr);

  t[id].sum = t[t[id].le].sum + t[t[id].ri].sum;
  return id;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> q;
  int len = n * m;
  root[0] = build(1, len);

  while (q--) {
    ++rootid;
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      int p = (x - 1) * m + y;

      int cur = get(root[rootid - 1], 1, len, p, false);

      if (cur == 0)
        root[rootid] = upd_p(root[rootid - 1], 1, len, p, 1);
      else
        root[rootid] = root[rootid - 1];
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      int p = (x - 1) * m + y;

      int cur = get(root[rootid - 1], 1, len, p, false);

      if (cur == 1)
        root[rootid] = upd_p(root[rootid - 1], 1, len, p, 0);
      else
        root[rootid] = root[rootid - 1];
    } else if (type == 3) {
      int x;
      cin >> x;

      int liml = (x - 1) * m + 1, limr = x * m;
      root[rootid] = upd_range(root[rootid - 1], 1, len, liml, limr);
    } else {
      int k;
      cin >> k;
      root[rootid] = root[k];
    }
    cout << t[root[rootid]].sum << '\n';
  }
}
