#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define matrix vector<vector<ll>>
int t;
ll a, b, L, R, m;

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
    cin >> a >> b >> L >> R >> m;

    ll f_R = get_fib(R, m),
    f_R1 = get_fib(R + 1, m),
    f_L_minus_1 = get_fib(L - 1, m),
    f_L = get_fib(L, m);

    ll val_R2 = (a * f_R + b * f_R1) % m,
    val_L1 = (a * f_L_minus_1 + b * f_L) % m;

    ll ans = (val_R2 - val_L1) % m;
    if (ans < 0) ans += m;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("FIB.INP", "r", stdin);
    freopen("FIB.OUT", "w", stdout);

    cin >> t;

    while(t--) solve();
    return 0;
}