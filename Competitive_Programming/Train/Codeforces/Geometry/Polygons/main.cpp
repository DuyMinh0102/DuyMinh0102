// Source: https://codeforces.com/problemset/problem/166/B
// Status: Sovled
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 06/08/2026 (DD/MM/YYYY).
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
  int id;

  Point(ll _x = 0, ll _y = 0, int _id = 0) : x(_x), y(_y), id(_id) {}

  Point operator-(const Point &other) const {
    return Point(x - other.x, y - other.y);
  }
  bool operator<(const Point &other) const {
    if (x != other.x)
      return x < other.x;
    return y < other.y;
  }

  ll dot(const Point &other) const { return x * other.x + y * other.y; }

  ll cross(const Point &other) const { return x * other.y - y * other.x; }

  ll dist2(const Point &other) const {
    ll dx = x - other.x, dy = y - other.y;
    return dx * dx + dy * dy;
  }
};
vector<Point> poly_a, poly;

int n, m;
bool mark[200005];

vector<Point> convex(vector<Point> &pts) {
  int len = pts.size(), k = 0;
  vector<Point> hull(2 * len);
  sort(pts.begin(), pts.end());

  for (int i = 0; i < len; ++i) {
    Point ab, bc;
    if (k >= 2) {
      ab = hull[k - 1] - hull[k - 2];
      bc = pts[i] - hull[k - 1];
    }

    while (k >= 2 && ab.cross(bc) < 0) {
      --k;

      if (k < 2)
        break;
      ab = hull[k - 1] - hull[k - 2];
      bc = pts[i] - hull[k - 1];
    }
    hull[k++] = pts[i];
  }

  for (int i = len - 2, t = k + 1; i >= 0; --i) {
    Point ab, bc;
    if (k >= t) {
      ab = hull[k - 1] - hull[k - 2];
      bc = pts[i] - hull[k - 1];
    }

    while (k >= t && ab.cross(bc) < 0) {
      --k;

      if (k < t)
        break;
      ab = hull[k - 1] - hull[k - 2];
      bc = pts[i] - hull[k - 1];
    }
    hull[k++] = pts[i];
  }

  hull.resize(k - 1);
  return hull;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll x, y;
    cin >> x >> y;

    poly_a.pb(Point(x, y, i));
    poly.pb(Point(x, y, i));
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    ll x, y;
    cin >> x >> y;

    poly.pb(Point(x, y, i + n));
  }

  vector<Point> convex_a = convex(poly_a), convex_full = convex(poly);
  for (const Point &i : convex_a)
    mark[i.id] = true;
  for (const Point &i : convex_full) {
    if (!mark[i.id]) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
