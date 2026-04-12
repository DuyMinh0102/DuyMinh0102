#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, INF = 2e9;
ll n, m, a[N], pre_dif[N], suf_dif[N];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    pre_dif[0] = suf_dif[n + 1] = 0;
    for (int i = 1; i < n; ++i) pre_dif[i] = max(0LL, a[i] - a[i + 1]) + pre_dif[i - 1];

    for (int i = n; i > 1; --i) suf_dif[i] = max(0LL, a[i] - a[i - 1]) + suf_dif[i + 1];

    for (int i = 0; i < m; ++i){
        int l, r; cin >> l >> r;

        if (l > r) cout << (suf_dif[r + 1] - suf_dif[l + 1]) << '\n';
        else cout << (pre_dif[r - 1] - pre_dif[l - 1]) << '\n';   
    }
}