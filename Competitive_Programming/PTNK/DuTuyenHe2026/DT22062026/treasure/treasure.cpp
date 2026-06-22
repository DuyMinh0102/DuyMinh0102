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

#define ll long long

const int MOD = 1000000007;
int n, k;
vector<int> b;
unordered_map<int, int> mem;

int forward(int cur_st) {
  if (mem.count(cur_st)) {
    return mem[cur_st];
  }

  int nxt_st = 0, w_pos = k - 1, r_pos = 0;

  for (int step_back = 1; step_back < k - 1; ++step_back) {
    int oldsz = k - step_back, newsz = oldsz - 1;

    int old_group = (cur_st >> r_pos) & ((1 << oldsz) - 1),
        rem = old_group & ((1 << newsz) - 1);

    nxt_st |= (rem << w_pos);

    r_pos += oldsz;
    w_pos += newsz;
  }

  return mem[cur_st] = nxt_st;
}

void solve() {
  cin >> n >> k;

  b.resize(n);
  for (int &val : b)
    cin >> val;

  vector<vector<int>> valid_cols(k + 1);
  int top_mask = (k > 1) ? ((1 << (k - 1)) - 1) : 0;

  for (int c = 0; c < (1 << k); ++c) {
    valid_cols[__builtin_popcount(c)].push_back(c & top_mask);
  }

  unordered_map<int, int> dp;
  dp[0] = 1;

  for (int req : b) {
    unordered_map<int, int> nxt_dp;

    for (auto &[state, ways] : dp) {
      int needed = req - __builtin_popcount(state);

      if (needed < 0 || needed > k)
        continue;

      int shifted = forward(state);

      for (int top : valid_cols[needed]) {
        int nxt_st = shifted | top;
        nxt_dp[nxt_st] = (nxt_dp[nxt_st] + ways) % MOD;
      }
    }

    dp = move(nxt_dp);
    if (dp.empty())
      break;
  }

  ll total = 0;
  for (auto &[state, ways] : dp) {
    total = (total + ways) % MOD;
  }

  cout << total;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  freopen("treasure.inp", "r", stdin);
  freopen("treasure.out", "w", stdout);
  solve();
  return 0;
}
