#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 200005;

// Variables
int n, m, k;
struct table {
  int l, r;
  bool operator<(const table &other) const { return l < other.l; }
};
vector<table> tables(N);
vector<vector<int>> h;

void sub1to7() {
  ll total = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= 2 * n; j += 2) {
      ll a = h[i][j], b = h[i][j + 1], minn = 2000000000;

      for (int v = 1; v <= k; ++v) {
        ll l = tables[v].l, r = tables[v].r, curr = 0;

        if (a < l || a > r)
          curr += min(abs(a - l), abs(a - r));
        if (b < l || b > r)
          curr += min(abs(b - l), abs(b - r));
        minn = min(minn, curr);
      }
      total += minn;
    }
  }

  cout << total;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("TG01TB.inp", "r", stdin);
  freopen("TG01TB.out", "w", stdout);

  cin >> m >> n >> k;
  h.resize(m + 1, vector<int>(2 * n + 1));

  for (int i = 1; i <= k; ++i) {
    cin >> tables[i].l >> tables[i].r;
  }
  sort(tables.begin() + 1, tables.begin() + k + 1);

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= 2 * n; ++j)
      cin >> h[i][j];
    sort(h[i].begin() + 1, h[i].begin() + 2 * n + 1);
  }

  sub1to7();
  return 0;
}
