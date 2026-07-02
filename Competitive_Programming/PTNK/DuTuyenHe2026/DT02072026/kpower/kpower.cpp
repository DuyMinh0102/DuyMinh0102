// Source:
// Status: Unsolved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 02/07/2026 (DD/MM/YYYY).
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
const int INF = 1000000000;

// Variables
int n, k, q;

int binpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res *= x;
    x *= x;
    y >>= 1;
  }
  return res;
}

void solve() {
  cin >> n >> k;

  vector<int> d;
  int tmp = n;
  while (tmp > 0) {
    d.pb(tmp % k);
    tmp /= k;
  }

  d.pb(0);

  int lst_inval = -1;
  for (int i = 0; i < d.size(); ++i) {
    if (d[i] > 1)
      lst_inval = i;
  }

  if (lst_inval != -1) {
    int z_pos = -1;

    for (int i = lst_inval + 1; i < d.size(); ++i) {
      if (d[i] == 0) {
        z_pos = i;
        break;
      }
    }

    d[z_pos] = 1;

    for (int i = 0; i < z_pos; ++i)
      d[i] = 0;
  }

  int ans = 0, lt = 1;
  for (int i = 0; i < d.size(); ++i) {
    ans += d[i] * lt;

    if (i < d.size() - 1)
      lt *= k;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("kpower.inp", "r", stdin);
  freopen("kpower.out", "w", stdout);

  cin >> q;
  while (q--) {
    solve();
  }
}
