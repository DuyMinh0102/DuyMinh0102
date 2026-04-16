// Source: No source
// Status: Solved
/*
Note: Total number of paths that has a length of k from node 1 to node n modulo 2017.

Solution: Use matrix multiplication to efficiently calculate the amount of paths.

Author: Nguyen Duy Minh - High School for the Gifted, VNU - HCM
Date: 03/02/2026
*/

#include <bits/stdc++.h>
#define ll long long
#define vi vector
using namespace std;
const int MOD = 2017;
int n, m;
ll k;
vi<vi<ll>> g(55, vi<ll>(55, 0));

vi<vi<ll>> multiply(const vi<vi<ll>> & A, const vi<vi<ll>>& B, int n) {
    vi<vi<ll>> C(n, vi<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vi<vi<ll>> power(vi<vi<ll>> A, ll k, int n) {   
    vi<vi<ll>> res(n, vi<ll>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (k > 0) {
        if (k % 2 == 1) {
            res = multiply(res, A, n);
        }
        A = multiply(A, A, n);
        k /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("cpath.inp", "r", stdin);
    freopen("cpath.out", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u - 1][v - 1] = (g[u - 1][v - 1] + 1) % MOD;
    }

    if (k == 0) {
        if (n == 1) cout << 1 % MOD << '\n';
        else cout << 0 << '\n';
        return 0;
    }

    vi<vi<ll>> res = power(g, k, n);

    cout << res[0][n - 1] << '\n';

    return 0;
}