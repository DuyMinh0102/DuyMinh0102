#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
ll n, k, fact_k[105], inverse[105];
int q;

ll binpow(ll x, ll y){
    ll res = 1;
    while(y){
        if (y & 1) res = (x * res) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fact_k[1] = 1;
    for (int i = 2; i <= 100; ++i) fact_k[i] = (fact_k[i - 1] * i) % MOD;
    for (int i = 100; i >= 1; --i) inverse[i] = binpow(fact_k[i], MOD - 2);

    cin >> q;

    while(q--){
        cin >> n >> k;

        ll a = 1;

        for (int i = k; i >= 1; --i){
            a = (n * a) % MOD;
            --n;
        }

        cout << (a * inverse[k]) % MOD << '\n';
    }
}