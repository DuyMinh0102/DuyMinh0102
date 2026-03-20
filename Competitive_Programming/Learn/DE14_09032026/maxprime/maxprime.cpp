#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7, N = 1e5;
ll minp[N + 5] = {0}, n;
struct p{
    ll cnt = 0, tmp = 0;
} freq[N + 5];
vector<ll> ps;

void sang(){
    minp[0] = minp[1] = 0;

    for (int i = 2; i * i <= N; ++i){
        if (minp[i] == 0){
            minp[i] = i;
            ps.push_back(i);
            for (int j = i * i; j <= N; j += i){
                if (minp[j] != 0) minp[j] = i;
            }
        }
    }
}

void process(ll x){
    vector<ll> primes;
    
    while(minp[x] != 0){
        ll y = minp[x];
        if (freq[y].tmp == 0){
            primes.push_back(y);
        }

        ++freq[y].tmp;
        freq[y].cnt = max(freq[y].cnt, freq[y].tmp);

        x /= y;
    }

    for (ll i : primes){
        cout << i << ' ';
        freq[i].tmp = 0;
    }
}

ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("maxprime.inp", "r", stdin); freopen("maxprime.out", "w", stdout);

    sang();

    cin >> n;

    process(8);

    for (int i = 1; i <= n; ++i){
        ll x; cin >> x;

        //process(x);
    }

    ll ans = 1;
    for (ll i : ps){
        if (freq[i].cnt != 0){
            cout << freq[i].cnt << '\n';
            ans = (ans * binpow(i, freq[i].cnt)) % MOD;
        }
    }   

    cout << ans;
}