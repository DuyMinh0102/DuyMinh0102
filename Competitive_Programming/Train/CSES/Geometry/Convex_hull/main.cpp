// Source: https://cses.fi/problemset/task/2195
// Status: Solved
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
const int N = 200000;

// Variables
int n;
struct Point {
  ll x, y;

  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

  ll dot(const Point &other) const { return x * other.x + y * other.y; }

  ll cross(const Point &other) const { return x * other.y - y * other.x; }

  ll dist2(const Point &other) const {
    ll dx = x - other.x, dy = y - other.y;

    return dx * dx + dy * dy;
  }

  bool operator<(const Point &other) const {
    if (x != other.x)
      return x < other.x;

    return y < other.y;
  }
};
vector<Point> points;

vector<Point> convex() {
  int k = 0;

  if (n <= 2)
    return points;

  vector<Point> hull(2 * n);
  sort(points.begin(), points.end());

  for (int i = 0; i < n; ++i) {
    Point ab, bc;
    if (k >= 2) {
      ab = Point(hull[k - 1].x - hull[k - 2].x, hull[k - 1].y - hull[k - 2].y);
      bc = Point(points[i].x - hull[k - 1].x, points[i].y - hull[k - 1].y);
    }

    while (k >= 2 && ab.cross(bc) < 0) {
      k--;
      if (k < 2)
        break;
      ab = Point(hull[k - 1].x - hull[k - 2].x, hull[k - 1].y - hull[k - 2].y);
      bc = Point(points[i].x - hull[k - 1].x, points[i].y - hull[k - 1].y);
    }
    hull[k++] = points[i];
  }

  for (int i = n - 2, t = k + 1; i >= 0; --i) {
    Point ab, bc;
    if (k >= t) {
      ab = Point(hull[k - 1].x - hull[k - 2].x, hull[k - 1].y - hull[k - 2].y);
      bc = Point(points[i].x - hull[k - 1].x, points[i].y - hull[k - 1].y);
    }

    while (k >= t && ab.cross(bc) < 0) {
      k--;
      if (k < t)
        break;
      ab = Point(hull[k - 1].x - hull[k - 2].x, hull[k - 1].y - hull[k - 2].y);
      bc = Point(points[i].x - hull[k - 1].x, points[i].y - hull[k - 1].y);
    }
    hull[k++] = points[i];
  }

  hull.resize(k - 1);
  return hull;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  points.resize(n);

  for (int i = 0; i < n; ++i)
    cin >> points[i].x >> points[i].y;

  vector<Point> hull = convex();

  cout << hull.size() << '\n';
  for (const Point &i : hull)
    cout << i.x << ' ' << i.y << '\n';
}
