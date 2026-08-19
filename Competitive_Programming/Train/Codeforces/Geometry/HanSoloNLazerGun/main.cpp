// Source: https://codeforces.com/contest/514/problem/B
// Status: Solved
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
#define pb push_back
#define ll long long

// Variables
int n;
struct point {
  int x, y;

  point() {};

  point(int _x, int _y) : x(_x), y(_y) {}
};
point Points[1005];
bool mark[1005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  point org;
  cin >> n >> org.x >> org.y;

  for (int i = 1; i <= n; ++i)
    cin >> Points[i].x >> Points[i].y;

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (mark[i])
      continue;

    ++ans;
    point a = point(Points[i].x - org.x, Points[i].y - org.y);

    for (int j = i + 1; j <= n; ++j) {
      if (mark[j])
        continue;
      point b = point(Points[j].x - org.x, Points[j].y - org.y);

      if (a.x * b.y - b.x * a.y == 0)
        mark[j] = true;
    }
  }

  cout << ans;
}
