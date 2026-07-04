#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, k, a[N];
ll dp[N] = {LLONG_MAX};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    dp[1] = 0;

    for (int i = 2; i <= n; ++i){
        ll mn = LLONG_MAX;

        for (int j = 1; j <= k; ++j){
            if (i - j > 0)  mn = min(mn, dp[i - j] + abs(a[i] - a[i - j]));
        }

        dp[i] = mn; 
    }

    cout << dp[n];
}