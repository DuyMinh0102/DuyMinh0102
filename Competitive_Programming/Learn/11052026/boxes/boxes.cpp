// Source: No source
// Status: Unsolved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 11/05/2026 (DD/MM/YYYY).
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
const int N = 25;

// Variables
int n, k;
int c[N][N], dp[N][N];
int ans = 2e9;
vector<bool> visited(N, false);

void recur(int id, vector<bool> &vis, int cost, int cnt) {
  if (cnt == (n - 1)) {
    ans = min(ans, cost);
    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      vis[i] = true;
      recur(i, vis, cost + c[id][i], cnt + 1);
      vis[i] = false;
    }
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("boxes.inp", "r", stdin);
  freopen("boxes.out", "w", stdout);

  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> c[i][j];
    }
  }

  if (n <= 10) {
    for (int i = 1; i <= n; ++i) {
      visited[i] = true;
      recur(i, visited, 0, 1);
      visited[i] = false;
    }
  }

  cout << ans;
}
