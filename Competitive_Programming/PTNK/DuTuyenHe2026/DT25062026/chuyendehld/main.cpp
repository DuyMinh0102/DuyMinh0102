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
int t, n, k;
struct chain {
  int l, r, len;
  bool operator<(const chain &other) const {
    if (len != other.len)
      return len < other.len;
    return l < other.l;
  }
};
vector<chain> chains, rem;
vector<int> nodes, p, sz;

void solve() {
  cin >> n >> k;

  chains.resize(k);
  p.assign(n + 1, 0);
  sz.assign(n + 1, 0);
  nodes.clear();
  rem.clear();
  int rootid = 0;

  for (int i = 0; i < k; ++i) {
    cin >> chains[i].l >> chains[i].r;
    chains[i].len = chains[i].r - chains[i].l + 1;

    if (i == 0)
      continue;

    if (chains[i].len > chains[rootid].len ||
        (chains[i].len == chains[rootid].len &&
         chains[i].l < chains[rootid].l)) {
      rootid = i;
    }
  }

  chain root_chain = chains[rootid];

  for (int i = 0; i < k; ++i)
    if (i != rootid)
      rem.push_back(chains[i]);

  sort(rem.begin(), rem.end());

  for (chain c : chains)
    for (int i = c.l + 1; i <= c.r; ++i)
      p[i] = i - 1;

  for (int i = root_chain.l; i <= root_chain.r; ++i)
    nodes.push_back(i);

  int m = nodes.size(), ptr = 0;

  for (int i = m - 1; i >= 0; --i) {
    int u = nodes[i];
    int limit = 0;

    if (i < m - 1) {
      limit = sz[nodes[i + 1]];
    }

    sz[u] = 1;
    if (i < m - 1) {
      sz[u] += sz[nodes[i + 1]];
    }

    while (ptr < rem.size() && rem[ptr].len <= limit) {
      p[rem[ptr].l] = u;
      sz[u] += rem[ptr].len;
      ++ptr;
    }
  }

  if (ptr < rem.size()) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int i = 1; i <= n; ++i)
      cout << p[i] << (i == n ? "" : " ");
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
