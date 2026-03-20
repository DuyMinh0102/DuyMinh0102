#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll n, m, a[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("eggs.inp", "r", stdin); freopen("eggs.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    int iperbox = (n + m - 1) / m;

    int cnt = 0, cursum = 0, res = 0;
    for (int i = 1; i <= n; ++i){
        cursum += a[i];
        ++cnt;

        if (cnt == iperbox || i == n){
            res = max(res, cursum);
            cursum = cnt = 0;
        }
    }

    cout << res;
}