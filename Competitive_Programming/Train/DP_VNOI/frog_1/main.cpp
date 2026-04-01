#include <bits/stdc++.h>
using namespace std;
long long n, h[100005];
long long dp[100005][2];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> h[i];

    dp[1][0] = dp[1][1] = 0;
    dp[2][0] = abs(h[2] - h[1]);
    dp[2][1] = dp[2][0];

    for (int i = 3; i <= n; ++i){
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + abs(h[i] - h[i - 1]);
        dp[i][1] = min(dp[i - 2][1], dp[i - 2][0]) + abs(h[i] - h[i - 2]);
    }

    cout << min(dp[n][0], dp[n][1]);
}