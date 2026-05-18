// Source: https://codeforces.com/contest/1689/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 14/05/2026.
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
int t, n, u, v;
vector<int> adj[300005];
int sz[300005], dp[300005];

void dfs(int c, int p) {
  sz[c] = 1;
  vector<int> ch;
  for (int nx : adj[c]) {
    if (nx != p) {
      dfs(nx, c);
      sz[c] += sz[nx];
      ch.pb(nx);
    }
  }
  if (ch.empty()) {
    dp[c] = 0;
  } else if (ch.size() == 1) {
    dp[c] = sz[ch[0]] - 1;
  } else {
    dp[c] = max(sz[ch[0]] - 1 + dp[ch[1]], sz[ch[1]] - 1 + dp[ch[0]]);
  }
}

int main() {

  ios_base::sync_with_stdio(0);

  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      adj[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    dfs(1, 0);
    cout << dp[1] << '\n';
  }

  return 0;
}
