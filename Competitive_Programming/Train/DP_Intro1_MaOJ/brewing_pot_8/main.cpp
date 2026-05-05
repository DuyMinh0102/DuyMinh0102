#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
ll n, a[505], dp[505][505], pref[505];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    a[0] = 1;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pref[i] = (pref[i - 1] + a[i]) % 100;
    }

    for (int len = 2; len <= n; ++len){
        for (int i = 1; i + len - 1 <= n; ++i){
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; ++k) dp[i][j] = min(dp[i][j], dp[k + 1][j] + dp[i][k] + ((pref[k] - pref[i - 1] + 100) % 100) * ((pref[j] - pref[k] + 100) % 100)); 
        }
    }

    cout << dp[1][n];
}