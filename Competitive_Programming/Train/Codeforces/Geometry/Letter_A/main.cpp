// Source: https://codeforces.com/problemset/problem/13/B
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 09/08/2026 (DD/MM/YYYY).
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
int t;
struct Point {
  ll x, y;

  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

  Point operator+(const Point &other) const {
    return Point(x + other.x, y + other.y);
  }

  Point operator-(const Point &other) const {
    return Point(x - other.x, y - other.y);
  }

  bool operator<(const Point &other) const {
    if (x != other.x)
      return x < other.x;

    return y < other.y;
  }

  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }

  ll dot(const Point &other) const { return x * other.x + y * other.y; }

  ll cross(const Point &other) const { return x * other.y - y * other.x; }

  ll dist2(const Point &other) const {
    ll dx = x - other.x, dy = y - other.y;

    return dx * dx + dy * dy;
  }
};

bool check(Point P, Point V, Point A) {
  Point VP = P - V, VA = A - V;

  if (VP.cross(VA) != 0)
    return false;

  ll dot = VP.dot(VA), dist = VA.dot(VA);

  if (5 * dot >= dist && 5 * dot <= 4 * dist)
    return true;

  return false;
}

void solve() {
  vector<vector<Point>> points(3, vector<Point>(2));

  for (int i = 0; i < 3; ++i) {
    cin >> points[i][0].x >> points[i][0].y >> points[i][1].x >> points[i][1].y;

    sort(points[i].begin(), points[i].end());
  }

  bool found = false;

  for (int i = 0; i < 3; ++i) {
    Point cross_st = points[i][0], cross_en = points[i][1];
    Point s1_st = points[(i + 1) % 3][0], s1_en = points[(i + 1) % 3][1];
    Point s2_st = points[(i + 2) % 3][0], s2_en = points[(i + 2) % 3][1];

    Point V, A, B;
    int shared = 0;

    if (s1_st == s2_st) {
      V = s1_st;
      A = s1_en;
      B = s2_en;
      ++shared;
    }
    if (s1_st == s2_en) {
      V = s1_st;
      A = s1_en;
      B = s2_st;
      ++shared;
    }
    if (s1_en == s2_st) {
      V = s1_en;
      A = s1_st;
      B = s2_en;
      ++shared;
    }
    if (s1_en == s2_en) {
      V = s1_en;
      A = s1_st;
      B = s2_st;
      ++shared;
    }

    if (shared != 1)
      continue;

    Point VA = A - V, VB = B - V;

    if (VA.dot(VB) < 0 || VA.cross(VB) == 0)
      continue;

    bool ok_1 = check(cross_st, V, A) && check(cross_en, V, B);
    bool ok_2 = check(cross_en, V, A) && check(cross_st, V, B);

    if (ok_1 || ok_2) {
      found = true;
      break;
    }
  }

  if (found)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--)
    solve();
}
