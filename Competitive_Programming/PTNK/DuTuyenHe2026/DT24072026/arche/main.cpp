// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
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
struct DSU {
  vector<int> par;

  DSU(int n) {
    par.resize(n + 1);
    for (int i = 1; i <= n; ++i)
      par[i] = i;
  }

  int findset(int v) { return (v == par[v]) ? v : par[v] = findset(par[v]); }

  void uni(int a, int b) {
    a = findset(a);
    b = findset(b);

    if (a != b)
      par[b] = a;
  }
};
struct Edge {
  int u, v, k;
};
int n, m;
vector<Edge> eqs;
vector<pair<int, int>> ineqs;
vector<int> val;

bool check(int x) {
  DSU dsu(n);

  for (auto &e : eqs)
    if (e.k > x)
      dsu.uni(e.u, e.v);

  for (auto &edge : ineqs)
    if (dsu.findset(edge.first) == dsu.findset(edge.second))
      return false;

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  val.pb(0);

  for (int i = 0; i < m; ++i) {
    int u, v, k;
    cin >> u >> v >> k;

    if (k == -1)
      ineqs.pb({u, v});
    else {
      eqs.pb({u, v, k});
      val.pb(k);
    }
  }

  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());

  int lo = 0, hi = val.size() - 1, ans = -1;

  while (lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);

    if (check(val[mid])) {
      ans = val[mid];
      hi = mid - 1;
    } else
      lo = mid + 1;
  }

  cout << ans;
}
