#include <bits/stdc++.h>;
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int n, m;
vector<int> dp;

int main(){
    cin >> n >> m;
    dp.resize(1 << n);

    dp[0] = 1;

    for (int c = 0; c < m; ++c){
        for (int r = 0; r < n; ++r){
            vector<int> nxt_dp(1 << n, 0);
            for (int mask = 0; mask < (1 << n); ++mask){
                if (dp[mask] == 0) continue;

                int nxt_0 = mask & ~(1 << r);
                nxt_dp[nxt_0] = (nxt_dp[nxt_0] + dp[mask]) % MOD;

                bool left = !(mask & (1 << r));
                bool above = (r == 0) || !(mask & (1 << (r - 1)));

                if (left && above){
                    int nxt_1 = mask | (1 << r);
                    nxt_dp[nxt_1] = (nxt_dp[nxt_1] + dp[mask]) % MOD;
                }
            }
            dp = nxt_dp;
        }
    }

    ll ans = 0;
    for (int count : dp) ans = (ans + count) % MOD;

    cout << ans;

    return 0;
}