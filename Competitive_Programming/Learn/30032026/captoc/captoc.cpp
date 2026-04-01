#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, x, a[N][N];
int dp[N][N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    freopen("captoc.inp", "r", stdin); freopen("captoc.out", "w", stdout);

    cin >> n >> x;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= x; ++j) cin >> a[i][j];
    }

    for (int i = 0; i <= x; ++i) dp[0][i] = 0;

    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= x; ++j){
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= j; ++k){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[i][k]);
            }
        }
    }

    cout << dp[n][x];
}