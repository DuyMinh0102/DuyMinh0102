#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll n, k;
ll a[N], pref[N], bit[N];
vector<ll> comp;

void update(int id, int v){
    for (; id <= n + 1; id += id & -id) bit[id] += v;
}

int query(int id){
    int cnt = 0;
    for (; id > 0; id -= id & -id) cnt += bit[id];
    return cnt;
}

int get_id(ll x){
    return (lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1);
}

int get_id_query(ll x){
    return (upper_bound(comp.begin(), comp.end(), x) - comp.begin());
}   

bool check(ll m){
    memset(bit, 0, sizeof(bit));
    ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        update(get_id(pref[i - 1]), 1);
        cnt += query(get_id_query(pref[i] - m));
    }

    return (cnt >= k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    comp.push_back(0);
    pref[0] = 0;
    ll minsum = 0, maxsum = 0, mx = LLONG_MIN, mn = LLONG_MAX;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        comp.push_back(pref[i]);

        minsum = min(minsum + a[i], a[i]);
        mn = min(mn, minsum);

        maxsum = max(maxsum + a[i], a[i]);
        mx = max(mx, maxsum);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    ll res = 0;
    while(mn <= mx){
        ll mid = mn + (mx - mn) / 2;

        if (check(mid)){
            res = mid;
            mn = mid + 1;
        }
        else mx = mid - 1;
    }

    cout << res;
}