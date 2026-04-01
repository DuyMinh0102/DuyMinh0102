#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7, base = 311;
string t, p;
ll k, n, m, hash_p = 0, ans = 0, cnt = 0, sz;
vector<bool> match;
vector<ll> power, hash_t;

ll get_hash(int l, int r){
    ll h = ((hash_t[r + 1] - hash_t[l] * power[r - l + 1]) % MOD + MOD) % MOD;
    if (h < 0) h += MOD;
    return h;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("swindow.inp", "r", stdin); 
    freopen("swindow.out", "w", stdout);

    getline(cin, t);
    getline(cin, p);
    while(!t.empty() && (t.back() == ' ' || t.back() == '\r')) t.pop_back();
    while(!p.empty() && (p.back() == ' ' || p.back() == '\r')) p.pop_back();
    
    cin >> k;
    n = t.size();
    m = p.size();

    if (m == 0 || k < m || n < k) {
        cout << 0;
        return 0;
    }

    sz = k - m + 1;
    match.resize(n + 5, false);
    power.resize(n + 5, 1);
    hash_t.resize(n + 5, 0);

    for (int i = 1; i <= n; ++i) 
        power[i] = (power[i - 1] * base) % MOD;

    for (int i = 0; i < m; ++i) 
        hash_p = (hash_p * base + p[i]) % MOD;

    for (int i = 0; i < n; ++i) 
        hash_t[i + 1] = (hash_t[i] * base + t[i]) % MOD;

    for (int i = 0; i <= n - m; ++i) 
        if (get_hash(i, i + m - 1) == hash_p) match[i] = true;

    for (int i = 0; i < sz; ++i) 
        if (match[i]) ++cnt;

    if (cnt > 0) ++ans;

    for (int i = 1; i <= n - k; ++i){
        if (match[i - 1]) --cnt;

        if (match[i + sz - 1]) ++cnt;

        if (cnt > 0) ++ans;
    }

    cout << ans;
}