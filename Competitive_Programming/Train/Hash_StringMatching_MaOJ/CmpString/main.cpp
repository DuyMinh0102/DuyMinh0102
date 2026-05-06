#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll p = 31, MOD = 1e9 + 7;
int q;
string s;
vector<ll> hashS, power;

ll getHash(int i, int j){
    return (hashS[j] - hashS[i - 1] * power[j - i + 1] + MOD * MOD) % MOD;
}

char CmpString(int a, int b, int l){
    ll x = getHash(a, a + l), y = getHash(b, b + l);

    if (x == y) return '=';

    int lo = 0, hi = l, diff = 0;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if (getHash(a, a + mid) == getHash(b, b + mid)){
            diff = mid + 1;
            lo = mid + 1;
        } else hi = mid - 1;
    }

    if (s[a + diff] < s[b + diff]) return '<';
    else return '>';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> q;
    
    int n = s.size();
    hashS.resize(n + 1);
    power.resize(n + 1);
    s = " " + s;

    hashS[0] = 0;
    power[0] = 1;
    for (int i = 1; i <= n; ++i){
        power[i] = (power[i - 1] * p) % MOD;
        hashS[i] = (hashS[i - 1]*p + s[i] - 'a' + 1) % MOD;
    }

    while(q--){
        int a, b, l; cin >> a >> b >> l;

        cout << CmpString(a, b, l) << '\n';
    }
}