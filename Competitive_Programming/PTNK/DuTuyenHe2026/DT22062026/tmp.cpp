#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int n, k;
vector<int> b;
unordered_map<int, int> shift_cache;

int forward(int current_state) {
  if (shift_cache.count(current_state)) {
    return shift_cache[current_state];
  }

  int nxt_st = 0;
  int w_pos = k - 1;
  int r_pos = 0;

  for (int step_back = 1; step_back < k - 1; ++step_back) {
    int oldsz = k - step_back;
    int newsz = oldsz - 1;

    int old_group = (current_state >> r_pos) & ((1 << oldsz) - 1);
    int rem = old_group & ((1 << newsz) - 1);

    nxt_st |= (rem << w_pos);

    r_pos += oldsz;
    w_pos += newsz;
  }

  return shift_cache[current_state] = nxt_st;
}

void solve() {
  cin >> n >> k;

  b.resize(n);
  for (int &val : b) {
    cin >> val;
  }

  vector<vector<int>> valid_cols(k + 1);
  int top_mask = (k > 1) ? ((1 << (k - 1)) - 1) : 0;

  for (int c = 0; c < (1 << k); ++c) {
    valid_cols[__builtin_popcount(c)].push_back(c & top_mask);
  }

  unordered_map<int, int> dp;
  dp[0] = 1;

  for (int required_minerals : b) {
    unordered_map<int, int> next_dp;

    for (const auto &[state, ways] : dp) {
      int needed = required_minerals - __builtin_popcount(state);

      if (needed < 0 || needed > k)
        continue;

      int shifted = forward(state);

      for (int top_bits : valid_cols[needed]) {
        int nxt_st = shifted | top_bits;
        next_dp[nxt_st] = (next_dp[nxt_st] + ways) % MOD;
      }
    }

    dp = move(next_dp);
    if (dp.empty())
      break;
  }

  long long total = 0;
  for (const auto &[state, ways] : dp) {
    total = (total + ways) % MOD;
  }

  cout << total << "\n";
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
