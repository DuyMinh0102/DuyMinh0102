#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("bai2.inp", "r", stdin); freopen("bai2.out", "w", stdout);

    cin >> n >> m;

    int incre = 0;
    ll st = 1, sum = n * (n + 1) / 2;
    if (sum > m) cout << -1;
    m -= sum;
    st += m / n;
    m -= (n * (m / n));

    if (m > 0) ++incre;

    cout << st << ' ' << n + st - 1 + incre;
}