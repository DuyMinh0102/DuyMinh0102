#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[5005][5005] = {{0}};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("daycs.inp", "r", stdin); freopen("daycs.out", "w", stdout);

    cin >> a >> b;
    int n = a.size(), m = b.size();

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i - 1] == b[j - 1]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
        }
    }   

    if (dp[n][m] == 0) cout << -1;
    else cout << dp[n][m];
}