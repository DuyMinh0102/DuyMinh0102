#include <bits/stdc++.h>
#define c_bit(x, i) ((x >> i) & 1)
#define ll long long
using namespace std;
const int N = 5e5 + 5, lg = 31;
ll n, x, a[N];
vector<ll> cand;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> x;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll res = 0;

    for (int i = 1; i <= n; ++i){
        if (a[i] > x) continue;

        if ((a[i] | x) == x) cand.push_back(a[i]);
    }

    ll sz = cand.size();

    cout << (sz*(sz - 1) / 2);
}