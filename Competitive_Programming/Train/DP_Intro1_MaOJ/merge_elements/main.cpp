#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 505, INF = 1e18;
ll n, a[N];
ll dp[N][N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[j] - a[i - 1]);
            }
        }
    }

    cout << dp[1][n];
}