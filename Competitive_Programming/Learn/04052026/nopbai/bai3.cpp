#include <bits/stdc++.h>
using namespace std;
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';
#define pb push_back
#define ll long long
#define vt vector
const int N = 505;
const ll INF = 1e18;
struct coords {
  int x, y, st;
  coords() {}

  coords(int _x, int _y, int _st) : x(_x), y(_y), st(_st) {}
};
int n;
vt<coords> p(N);
vt<bool> visited(N, false);
vt<double> mindist(N, INF);

double get_dist(coords a, coords b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("bai3.inp", "r", stdin);
  freopen("bai3.out", "w", stdout);

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> p[i].x >> p[i].y >> p[i].st;
    if (p[i].st == 1)
      mindist[i] = 0.0;
  }

  double total = 0;

  for (int i = 1; i <= n; ++i) {
    int u = -1;
    double best = INF;

    for (int j = 1; j <= n; ++j) {
      if (!visited[j] && (u == -1 || mindist[j] < best)) {
        u = j;
        best = mindist[j];
      }
    }

    if (u == -1)
      break;

    visited[u] = true;
    total += mindist[u];

    for (int j = 1; j <= n; ++j) {
      if (!visited[j]) {
        double dist = get_dist(p[u], p[j]);

        if (p[u].st == 1 && p[j].st == 1)
          dist = 0;

        if (dist < mindist[j])
          mindist[j] = dist;
      }
    }
  }

  cout << fixed << setprecision(3) << total;
}
