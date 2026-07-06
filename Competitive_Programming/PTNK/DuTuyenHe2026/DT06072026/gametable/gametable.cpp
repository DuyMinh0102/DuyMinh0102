// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 06/07/2026 (DD/MM/YYYY).
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
#define pl pair<ll, int>

// Variables
int h, w;
ll a[16][16], colsum[16][1 << 15], s;
pl lsum[1 << 8], rsum[1 << 8];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("gametable.inp", "r", stdin);
  freopen("gametable.out", "w", stdout);

  cin >> h >> w;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      cin >> a[i][j];

  cin >> s;

  for (int j = 0; j < w; ++j) {
    colsum[j][0] = 0;
    for (int r = 1; r < (1 << h); ++r) {
      int bit = r & -r;
      int id = __builtin_ctz(bit);

      colsum[j][r] = colsum[j][r ^ bit] + a[id][j];
    }
  }

  int lsz = w / 2;
  int rsz = w - lsz;

  for (int r = 1; r < (1 << h); ++r) {
    lsum[0] = {0LL, 0};

    for (int m = 1; m < (1 << lsz); ++m) {
      int bit = m & -m;
      int id = __builtin_ctz(bit);
      lsum[m] = {lsum[m ^ bit].first + colsum[id][r], m};
    }

    rsum[0] = {0LL, 0};
    for (int m = 1; m < (1 << rsz); ++m) {
      int bit = m & -m;
      int id = __builtin_ctz(bit);
      rsum[m] = {rsum[m ^ bit].first + colsum[lsz + id][r], m};
    }

    sort(rsum, rsum + (1 << rsz));

    for (int m = 0; m < (1 << lsz); ++m) {
      ll target = s - lsum[m].first;

      if (target < 0)
        continue;

      int lo = 0, hi = (1 << rsz) - 1;
      while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);

        if (rsum[mid].first == target) {
          cout << "YES\n";

          int final = lsum[m].second | (rsum[m].second << lsz);

          vector<pair<int, int>> ops;

          for (int i = 0; i < h; ++i)
            if (!((r >> i) & 1))
              ops.pb({1, i + 1});

          for (int j = 0; j < w; ++j)
            if (!((final >> j) & 1))
              ops.pb({2, j + 1});

          cout << ops.size() << '\n';
          for (auto &op : ops)
            cout << op.first << ' ' << op.second << '\n';
          return 0;
        } else if (rsum[mid].first < target)
          lo = mid + 1;
        else
          hi = mid - 1;
      }
    }
  }

  cout << "NO";
}
