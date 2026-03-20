#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define matrix vector<vector<ll>>
const ll MOD = 1e9 + 7;
int t;
ll a, b, n;

matrix multiply(matrix A, matrix B, ll m){
    matrix C(2, vector<ll>(2, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return C;
}

matrix power(matrix A, ll p, ll m){
    matrix res = {{1, 0}, {0, 1}};
    while (p > 0){
        if (p % 2 == 1) res = multiply(res, A, m);
        A = multiply(A, A, m);
        p /= 2;
    }
    return res;
}

ll get_fib(ll n, ll m){
    if (n == 0) return 0;
    matrix T = {{1, 1}, {1, 0}};
    matrix res = power(T, n - 1, m);
    return res[0][0];
}

void solve(){
    cin >> a >> b >> n;

    if (n == 0) cout << a << '\n';
    else if (n == 1) cout << b << '\n';

    ll f_n = get_fib(n, MOD);
    ll f_n_m1 = get_fib(n - 1, MOD);

    cout << (a * f_n_m1 + b*f_n) % MOD << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("fib3.inp", "r", stdin);
    freopen("fib3.out", "w", stdout);

    cin >> t;

    while(t--) solve();
    return 0;
}