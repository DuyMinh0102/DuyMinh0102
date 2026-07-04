#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
ll n, a[N];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;

    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0){
        cout << 0;
        return 0;
    }

    ll t = sum / 3;
    ll t_2 = sum / 3 * 2;

    ll cur = 0;
    ll cnt = 0, t_cnt = 0;
    for (int i = 1; i < n; ++i){
        cur += a[i];
        if (cur == t_2) cnt += t_cnt;
        if (cur == t) ++t_cnt;
    }

    cout << cnt;
}