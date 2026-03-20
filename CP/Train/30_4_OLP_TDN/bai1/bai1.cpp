#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 7e4 + 5;
int n, q;
ll a[N], mx = 0, pre[N];
bool all2k = true;
vector<ll> p(N, 0);
vector<int> check(N, 0);

void sang(){
    p[0] = p[1] = 0;

    for (int i = 2; i * i < N; ++i){
        if (p[i] == 0){
            p[i] = i;

            for (int j = i * i; j < N; j += i){
                if (p[j] == 0) p[j] = i;
            }
        }
    }
}

void check_all2k(ll x, int id){
    pre[id] = 0;
    if (check[x] == 0){
        while(p[x] != 0){
            if (p[x] != 2){
                check[x] = -1;
                all2k = false;
                return;
            }

            ++pre[id];

            x /= p[x];
        }

        check[x] = 1;
    }
}

void sub1(){
    pre[0] = 1;

    for (int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] * a[i];
    }

    while(q--){
        int l, r; cin >> l >> r;

        ll cur = pre[r] / pre[l - 1];

        ll sq = sqrt(cur);

        if (sq*sq == cur) cout << "YES\n";
        else cout << "NO\n";
    }
}

void sub2(){
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];

    while(q--){
        int l, r; cin >> l >> r;

        if ( (pre[r] - pre[l - 1]) & 1) cout << "NO\n";
        else cout << "YES\n";
    }
}

void sub3(){}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bai1.inp", "r", stdin);
    freopen("bai1.out", "w", stdout);

    sang();

    cin >> n >> q;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
        if (all2k) check_all2k(a[i], i);
    }

    if (n <= 18 && q <= 18 && mx <= 10) sub1();
    else if (all2k) sub2();
    else sub3();
}