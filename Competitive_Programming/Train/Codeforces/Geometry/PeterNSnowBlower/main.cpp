// Source: https://codeforces.com/contest/613/problem/A
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 05/08/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define ll long long
const int N = 100000;
const double INF = 2e18;
const double PI = acos(-1.0);

// Variables
struct Point {
  ll x, y;

  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

  Point operator-(const Point &other) const {
    return Point(x - other.x, y - other.y);
  };

  ll vo_huong(const Point &other) const { return x * other.x + y * other.y; }

  ll co_huong(const Point &other) const { return x * other.y - other.x * y; }

  ll dist2(const Point &other) const {
    ll dx = x - other.x, dy = y - other.y;
    return dx * dx + dy * dy;
  }
};
int n;
Point p;
Point points[N + 5];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> p.x >> p.y;

  for (int i = 0; i < n; ++i)
    cin >> points[i].x >> points[i].y;

  double mx_dist = 0.0, mn_dist = INF;
  for (int i = 0; i < n; ++i) {
    double d2 = p.dist2(points[i]);

    mx_dist = max(mx_dist, d2);
    mn_dist = min(mn_dist, d2);

    Point a = points[i], b = points[(i + 1) % n];

    Point ab = b - a, ba = a - b, ap = p - a, bp = p - b;

    ll dot1 = ab.vo_huong(ap), dot2 = ba.vo_huong(bp);

    if (dot1 > 0 && dot2 > 0) {
      double c = (double)(ab.co_huong(ap));

      mn_dist = min(mn_dist, (c * c) / a.dist2(b));
    }
  }

  double S = PI * (mx_dist - mn_dist);

  cout << fixed << setprecision(18) << S;
}
