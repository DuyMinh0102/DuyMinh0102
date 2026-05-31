// Source: https://codeforces.com/contest/1498/problem/C
// Status: Solved
/*
Note: When a particle of DA (decay age) of k moves to a plane, that plane
creates another DA age k - 1 which travels in the oposite direction, and
continue moving. Count the amount of particles after shooting a DA of age k into
a set of planes modulo 10^9 + 7.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 28/05/2026 (DD/MM/YYYY).
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
const ll MOD = 1e9 + 7;

// Variables
int t, n, k;
ll l, r, r_sum;
vector<vector<ll>> dp;
vector<ll> bit;

void upd(int id, int val) {
  for (; id <= n + 1; id += id & -id)
    bit[id] = (bit[id] + val);
}

ll sum(int id) {
  ll s = 0;
  for (; id > 0; id -= id & -id)
    s = (s + bit[id]) % MOD;
  return s;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> k;

    dp.assign(k + 1, vector<ll>(n + 1, 0));

    for (int i = 0; i <= n; ++i)
      dp[1][i] = 1;
    for (int i = 1; i <= k; ++i)
      dp[i][0] = 1;

    for (int j = 2; j <= k; ++j) {
      bit.assign(n + 2, 0);

      for (int x = 0; x <= n; ++x)
        upd(x + 1, dp[j - 1][x]);

      for (int i = 1; i <= n; ++i) {
        l = n - i + 1;
        r = n;

        r_sum = 0;
        if (l <= r) {
          r_sum = (sum(r) - sum(l - 1) % MOD + MOD) % MOD;
        }
        dp[j][i] = (1 + r_sum) % MOD;
      }
    }

    cout << dp[k][n] << '\n';
  }
}
