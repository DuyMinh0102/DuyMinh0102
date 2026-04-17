// Source: ..
// Status: Unsolved
/*
Note: ..

Solution: ..

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: No date (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e3 + 5;
int n, k, a[N + 5];
ll pre[2*N + 5] = {0};

ll sq(ll x){ return x * x; }

void subk2(){
    pre[0] = 0;
    for (int i = 1; i < 2*n; ++i) pre[i] = pre[i - 1] + a[i];

    ll res = LLONG_MAX;
    for (int i = 1; i <= n; ++i){
        ll curr = sq(pre[i - 1] - pre[i -])
    }

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    
    cin >> n >> k;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i + n] = a[i];
    }

    if (k == 2) subk2();

}