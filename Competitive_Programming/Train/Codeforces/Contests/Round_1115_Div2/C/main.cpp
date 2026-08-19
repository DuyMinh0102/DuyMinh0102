// Source: https://codeforces.com/contest/2252/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/08/2026 (DD/MM/YYYY).
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
int t, n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    cin >> n >> m;
    int mn_rem = m;

    vector<vector<ll>> grid(n + 5, vector<ll>(m + 5));
    vector<ll> v(n + 1);
    priority_queue<ll, vector<ll>, greater<ll>> q, tmp;
    ll sum = 0;

    for (int i = 1; i <= n; ++i)
      cin >> v[i];

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> grid[i][j];

    for (int i = n; i >= 1; --i) {
      for (int j = 1; j <= m; ++j) {
        q.push(grid[i][j]);
        sum += grid[i][j];
        if (q.size() >= m) {
          sum -= q.top();
          q.pop();
        }
      }

      if (sum >= v[i]) {
        int needed = m - 1;

        while (true) {
          if (sum - q.top() < v[i] || q.empty())
            break;

          tmp.push(q.top());
          sum -= q.top();
          q.pop();
          --needed;
        }

        mn_rem = min(mn_rem, needed);

        while (!tmp.empty()) {
          sum += tmp.top();
          q.push(tmp.top());
          tmp.pop();
        }
      }
    }

    cout << mn_rem << '\n';
  }
}
