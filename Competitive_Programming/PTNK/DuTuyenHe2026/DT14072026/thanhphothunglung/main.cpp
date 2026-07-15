// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 14/07/2026 (DD/MM/YYYY).
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
const int N = 1005;
const int MN_INF = -2e9 - 7;

// Variables
int m, n;
vector<vector<int>> h(N, vector<int>(N, MN_INF)),
    mx_up(N, vector<int>(N, MN_INF)), mx_down(N, vector<int>(N, MN_INF)),
    mx_left(N, vector<int>(N, MN_INF)), mx_right(N, vector<int>(N, MN_INF));
vector<vector<bool>> valley(N, vector<bool>(N, false)),
    vis(N, vector<bool>(N, false));
int dr[] = {0, 1, 0, -1}, dc[] = {-1, 0, 1, 0};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> m >> n;

  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> h[i][j];

  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      mx_up[i][j] = max(mx_up[i - 1][j], h[i - 1][j]);
      mx_left[i][j] = max(mx_left[i][j - 1], h[i][j - 1]);
    }

  for (int i = m; i > 0; --i)
    for (int j = n; j > 0; --j) {
      mx_down[i][j] = max(mx_down[i + 1][j], h[i + 1][j]);
      mx_right[i][j] = max(mx_right[i][j + 1], h[i][j + 1]);
    }

  for (int i = 2; i < m; ++i)
    for (int j = 2; j < n; ++j)
      if (h[i][j] <
          min({mx_up[i][j], mx_down[i][j], mx_left[i][j], mx_right[i][j]}))
        valley[i][j] = true;

  int mx = 0;
  for (int i = 2; i < m; ++i)
    for (int j = 2; j < n; ++j) {
      if (valley[i][j] && !vis[i][j]) {
        int cur = 0;
        queue<pair<int, int>> q;

        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty()) {
          int x = q.front().first, y = q.front().second;
          q.pop();
          ++cur;

          for (int k = 0; k < 4; ++k) {
            int u = x + dr[k], v = y + dc[k];

            if (valley[u][v] && !vis[u][v]) {
              vis[u][v] = true;
              q.push({u, v});
            }
          }
        }

        mx = max(mx, cur);
      }
    }

  cout << mx;
}
