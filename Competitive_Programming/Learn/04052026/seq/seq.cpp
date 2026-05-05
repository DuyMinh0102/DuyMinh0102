#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 16500;
int t, n;
ll a[N], pref[N], res;

ll recur(int l, int r){
    if (l >= r) return 0;
    ll cur_sum = pref[r] - pref[l - 1];
    if (cur_sum == 0) return r - l;
    if (cur_sum & 1) return 0;

    ll target = pref[l - 1] + (cur_sum / 2);

    int it = lower_bound(pref + l, pref + r, target) - pref;

    if (pref[it] != target) return 0;

    return 1 + max(recur(l, it), recur(it + 1, r));
}

void solve(){
    res = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    cout << recur(1, n);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("seq.inp", "r", stdin);
    freopen("seq.out", "w", stdout);

    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
}