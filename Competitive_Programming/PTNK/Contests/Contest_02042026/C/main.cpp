#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1000000007;
const int MAX = 200005;
ll fact[MAX], n, k;

ll power(ll base, ll exp){
    ll res = 1;
    base %= MOD;
    while (exp > 0){
        if (exp % 2 == 1){
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n){
    return power(n, MOD - 2);
}

void precompute(){
    fact[0] = 1;
    for (int i = 1; i < MAX; i++){
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    precompute();

    cin >> n >> k;

    if (n == 1){
        cout << 1 << "\n";
        return 0;
    }

    if (k == 0){
        cout << fact[n - 1] << "\n";
        return 0;
    }

    if (k > n / 2){
        cout << 0 << "\n";
        return 0;
    }

    ll num = (fact[n - k - 1] * fact[n - k]) % MOD;
    ll den = modInverse(fact[n - 2 * k]);
    ll ans = (num * den) % MOD;

    cout << ans << "\n";

    return 0;
}