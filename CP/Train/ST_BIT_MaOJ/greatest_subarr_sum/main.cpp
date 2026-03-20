#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const ll INF = 1e15;
int n, q;
ll a[N];
struct ST{
    ll sum, pref, suf, mx;

    ST() : sum(0), pref(0), suf(0), mx(0) {}

    ST(ll _sum, ll _pref, ll _suf, ll _mx): sum(_sum), pref(_pref), suf(_suf), mx(_mx) {}
} t[4*N];

ST merge(ST a, ST b){
    return ST(
        a.sum + b.sum,
        max(a.pref, a.sum + b.pref),
        max(b.suf, b.sum + a.suf),
        max({a.mx, b.mx, a.suf + b.pref})
    );
}

void build(int k, int l, int r){
    if (l == r){
        t[k].sum = t[k].mx = t[k].pref = t[k].suf = a[l];
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(k << 1, l, mid);
    build((k << 1) | 1, mid + 1, r);
    t[k] = merge(t[k << 1], t[(k << 1) | 1]);
}

ST query(int k, int l, int r, int u, int v){
    if (l > v || r < u) return ST(0, -INF, -INF, -INF);
    if (u <= l && r <= v) return t[k];

    int mid = l + ((r - l) >> 1);
    return merge( query(k << 1, l, mid, u, v) , query((k << 1) | 1, mid + 1, r, u, v) );
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    cin >> q;

    while(q--){
        int l, r; cin >> l >> r;

        cout << query(1, 1, n, l, r).mx << '\n';
    }
}