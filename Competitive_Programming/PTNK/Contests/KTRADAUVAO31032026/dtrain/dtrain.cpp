#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, K = 2001;
ll n, k, dp[N][K], p[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("dtrain.inp", "r", stdin); freopen("dtrain.out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) cin >> p[i];

    for (int j = 1; j <= k; ++j){
        for (int i = j; i <= n; ++i){
            
        }
    }

    ll res = 2e18;
    for (int i = 1; i <= k; ++i) res = min(res, dp[n][i]);
}