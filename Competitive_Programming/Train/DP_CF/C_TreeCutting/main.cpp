// Source: https://codeforces.com/contest/1946/problem/C
// Status: Unsolved
/*
Note: Determine the biggest smallest component size after deleting k edges.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 13/05/2026 (DD/MM/YYYY).
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
int n, k, t, cnt;
vector<vector<int>> g;

int dfs(int u, int p, int mid) {
  int sz = 1;
  for (int v : g[u]) {
    if (v != p) {
      sz += dfs(v, u, mid);
    }
  }

  if (sz >= mid) {
    ++cnt;
    return 0;
  }

  return sz;
}

bool check(int mid) {
  cnt = 0;
  int r = dfs(1, 0, mid);

  if (cnt > k || (cnt == k && r >= mid))
    return true;

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> k;
    g.assign(n + 1, vector<int>());

    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;

      g[u].pb(v);
      g[v].pb(u);
    }

    int lo = 1, hi = n, ans = 1;

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (check(mid)) {
        ans = mid;
        lo = mid + 1;
      } else
        hi = mid - 1;
    }

    cout << ans << '\n';
  }
}
