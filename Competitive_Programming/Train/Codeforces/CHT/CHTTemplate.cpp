#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

// mutable: struct/class member is allowed to be modified even if the object is
// accessed via const reference or const iterator
struct Line {
  mutable ll m, k, p;
  bool operator<(const Line &o) const { return m < o.m; }
  bool operator<(ll x) const { return p < x; }
};

struct DynamicCHT : multiset<Line, less<>> {
  static const ll inf = 1e18;
  ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }

  bool isect(iterator x, iterator y) {
    if (y == end())
      return x->p = inf, 0;
    if (x->m == y->m)
      x->p = x->k > y->k ? inf : -inf;
    else
      x->p = div(y->k - x->k, x->m - y->m);
    return x->p >= y->p;
  }

  void add(ll m, ll k) {
    auto z = insert({m, k, 0}), y = z++, x = y;
    while (isect(y, z))
      z = erase(z);
    if (x != begin() && isect(--x, y))
      isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }

  ll query(ll x) {
    auto l = *lower_bound(x);
    return l.m * x + l.k;
  }
};

struct StaticCHT {
  struct Line {
    ll m, k;
  };
  vector<Line> hull;
  int ptr = 0;

  bool redundant(Line l1, Line l2, Line l3) {
    return (__int128)(l3.k - l1.k) * (l1.m - l2.m) <=
           (__int128)(l2.k - l1.k) * (l1.m - l3.m);
  }

  void add(ll m, ll k) {
    Line l = {m, k};
    while (hull.size() >= 2 && redundant(hull[hull.size() - 2], hull.back(), l))
      hull.pop_back();
    hull.push_back(l);
  }

  ll query(ll x) {
    if (ptr >= hull.size())
      ptr = hull.size() - 1;
    while (ptr + 1 < hull.size() && hull[ptr + 1].m * x + hull[ptr + 1].k >=
                                        hull[ptr].m * x + hull[ptr].k)
      ptr++;
    return hull[ptr].m * x + hull[ptr].k;
  }
};
