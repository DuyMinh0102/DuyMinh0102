// Source: https://codeforces.com/contest/919/problem/D
// Status: Solved
/*
Note: Given a graph with n nodes and m edges, each node is assigned a lowercase
latin letter (a - z). Find the path with the highest value. The value of a path
is determined by the frequency of the character appeared the most on that path.

Solution:
- Create an adjacency list and calculate in_degree (how many edges that points
towards this vertex) of each vertex.
- Push every vertex with in_degree == 0 to a queue.
- Caclulate dp (dp[i][c] the most amount of times character c appeared on the
path contains i).
- in_degree[i] -= 1 (since we already proceseed one edge).
- Check
  - If proc (amount of processed vertices) < n: haven't processed all vertices
-> some vertices weren't pushed into queue -> some vertices have many edges
pointing to them -> there is a cycle -> output -1
  - Output mx

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 21/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                   \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 300005;

// Variables
int n, m;
int dp[N][26];
vector<int> g[N], in_degree(N, 0);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  string s;
  cin >> s;
  s = ' ' + s;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;

    g[u].pb(v);
    ++in_degree[v];
  }

  int proc = 0, mx = 0;
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (in_degree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ++proc;

    int char_id = s[u] - 'a';
    ++dp[u][char_id];

    for (int c = 0; c < 26; ++c) {
      mx = max(mx, dp[u][c]);
    }

    for (int v : g[u]) {
      for (int c = 0; c < 26; ++c) {
        dp[v][c] = max(dp[v][c], dp[u][c]);
      }

      --in_degree[v];
      if (in_degree[v] == 0) q.push(v);
    }
  }

  if (proc < n)
    cout << -1;
  else
    cout << mx;
}
