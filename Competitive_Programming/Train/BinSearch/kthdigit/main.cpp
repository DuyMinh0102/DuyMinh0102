#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
ll k;
vector<ll> num(20, 0);

ll binpow(ll x, ll y){
    ll res = 1;
    while(y){
        if (y & 1) res = (res * x);
        x = (x * x);
        y >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> k;

    for (int i = 1; i <= 18; ++i){
        num[i] = 9 * i * binpow(10, i - 1);
        num[i] += num[i - 1];
    }

    int it = lower_bound(num.begin() + 1, num.begin() + 19, k) - (num.begin());

    ll tmp = k - num[it - 1] - 1;
    ll n = tmp / it + binpow(10, it - 1);
    string x = to_string(n);

    cout << x[tmp % it];  
}