#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n;
ll bit[N] = {0LL}, pref[N] = {0LL}, pos[N];
vector<ll> compress;

void update(int id, ll val){
    for (; id <= n + 1; id += (id & -id)) bit[id] += val;
}

ll query(int id){
    ll res = 0;
    for (; id > 0; id -= (id & -id)) res += bit[id];
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    pref[0] = 0;
    compress.push_back(pref[0]);
    for (int i = 1; i <= n; ++i){
        cin >> pref[i];
        pref[i] += pref[i - 1];
        compress.push_back(pref[i]);
    }

    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());

    for (int i = 0; i <= n; ++i){
        int idx = lower_bound(compress.begin(), compress.end(), pref[i]) - compress.begin() + 1;

        pos[i] = idx;
    }

    ll ans = 0;
    for (int i = 0; i <= n; ++i){
        ans += query(pos[i]);

        update(pos[i], 1);  
    }

    cout << ans;
}