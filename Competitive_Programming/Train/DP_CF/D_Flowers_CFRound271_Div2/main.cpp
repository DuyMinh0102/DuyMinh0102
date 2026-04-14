#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
ll dp[N], pref[N];
int t, k, a, b;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> t >> k;
    
    dp[0] = 1;
    
    for (int i = 1; i < N; i++){
        dp[i] = dp[i - 1];
        if (i >= k){
            dp[i] = (dp[i] + dp[i - k]) % mod;
        }
    }
    
    pref[0] = 0;
    for (int i = 1; i < N; i++){
        pref[i] = (pref[i - 1] + dp[i]) % mod;
    }
    
    while (t--){
        cin >> a >> b;
        ll ans = (pref[b] - pref[a - 1] + mod) % mod;
        cout << ans << "\n";
    }
    
    return 0;
}