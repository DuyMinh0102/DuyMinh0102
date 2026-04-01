#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, items = 0;
ll dp[1005][10005], v[1005], w[1005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("chondo.inp", "r", stdin); 
    freopen("chondo.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    int curr_w = m;
    for (int i = n; i > 0; --i){
        if (dp[i][curr_w] != dp[i - 1][curr_w]){
            items += w[i];
            curr_w -= w[i];
        }
    }

    cout << dp[n][m] << '\n' << items;
}