#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
ll n, k, d;
ll dp1[105], dp2[105];


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> k >> d;
    
    dp1[0] = 1;
    dp2[0] = 1;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (i >= j){
                dp1[i] = (dp1[i] + dp1[i - j]) % mod;
            }
        }
        for (int j = 1; j < d; j++){
            if (i >= j){
                dp2[i] = (dp2[i] + dp2[i - j]) % mod;
            }
        }
    }
    
    ll ans = (dp1[n] - dp2[n] + mod) % mod;
    cout << ans << "\n";
    
    return 0;
}