// Source: https://codeforces.com/problemset/problem/87/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 08/08/2026 (DD/MM/YYYY).
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
struct Point {
  ll x, y;

  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

  Point operator-(const Point &other) const {
    return Point(x - other.x, y - other.y);
  }

  Point operator+(const Point &other) const {
    return Point(x + other.x, y + other.y);
  }

  bool operator<(const Point &other) const {
    if (x != other.x)
      return x < other.x;

    return y < other.y;
  }

  bool operator==(const Point &other) const {
    return (x == other.x && y == other.y);
  }

  ll dot(const Point &other) const { return x * other.x + y * other.y; }

  ll cross(const Point &other) const { return x * other.y - y * other.x; }

  ll dist2(const Point &other) const {
    ll dx = x - other.x, dy = y - other.y;
    return dx * dx + dy * dy;
  }
};

void reorder(vector<Point> &poly) {
  int pos = 0;
  for (int i = 1; i < (int)poly.size(); ++i) {
    if (poly[i].y < poly[pos].y ||
        (poly[i].y == poly[pos].y && poly[i].x < poly[pos].x))
      pos = i;
  }

  rotate(poly.begin(), poly.begin() + pos, poly.end());
}

int half(const Point &p) { return (p.y > 0 || (p.y == 0 && p.x > 0)) ? 0 : 1; }

bool cmp(const Point &a, const Point &b) {
  int ha = half(a), hb = half(b);
  if (ha != hb)
    return ha < hb;
  return a.cross(b) > 0;
}
int m;
vector<Point> polygon[3], edges, merged, S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 3; ++i) {
    int n;
    cin >> n;

    polygon[i].resize(n);
    for (int j = 0; j < n; ++j) {
      cin >> polygon[i][j].x >> polygon[i][j].y;
    }

    reorder(polygon[i]);
  }

  for (int i = 0; i < 3; ++i) {
    int n = polygon[i].size();
    for (int j = 0; j < n; ++j)
      edges.pb(polygon[i][(j + 1) % n] - polygon[i][j]);
  }

  sort(edges.begin(), edges.end(), cmp);

  for (const auto &e : edges) {
    if (merged.empty())
      merged.pb(e);
    else {
      if (merged.back().cross(e) == 0 && merged.back().dot(e) > 0)
        merged.back() = merged.back() + e;
      else
        merged.pb(e);
    }
  }

  S.pb(polygon[0][0] + polygon[1][0] + polygon[2][0]);

  for (const auto &e : merged)
    S.pb(S.back() + e);

  S.pop_back();

  cin >> m;
  while (m--) {
    ll x, y;
    cin >> x >> y;

    Point q(x * 3, y * 3);

    q = q - S[0];
    if (q.x == 0 && q.y == 0) {
      cout << "YES\n";
      continue;
    }

    auto V = [&](int id) { return S[id] - S[0]; };

    if (V(1).cross(q) < 0 || V(S.size() - 1).cross(q) > 0) {
      cout << "NO\n";
      continue;
    }

    int lo = 1, hi = S.size() - 1;
    while (hi - lo > 1) {
      int mid = lo + ((hi - lo) >> 1);

      if (V(mid).cross(q) >= 0)
        lo = mid;
      else
        hi = mid;
    }

    Point edge = V(hi) - V(lo), to_q = q - V(lo);

    if (edge.cross(to_q) >= 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
