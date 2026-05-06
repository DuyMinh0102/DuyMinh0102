// Source: Problems/BT_20260302.pdf
// Status: Solved
/*
Note: Find the total number of ways to reach sum n using 1, 2 or 3.

Solution: Use matrix multiplication and matrix binary exponentiation.

Author: Nguyen Duy Minh - High School for the Gifted, VNU - HCM
Date: 03/02/2026
*/

#include <bits/stdc++.h>
#define ll long long
#define vi vector
using namespace std;
ll MOD, n;
vi<vi<ll>> u = 
{
    {1, 1, 1},
    {1, 0, 0},
    {0, 1, 0}
};
vi<vi<ll>> a = 
{
    {1, 0, 0},
    {1, 0, 0},
    {0, 0, 0}
};

void multi(vi<vi<ll>>& A, vi<vi<ll>>& B){
    vi<vi<ll>> C(3, vi<ll>(3));

    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            for (int k = 0; k < 3; ++k){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % MOD;
            }
        }
    }

    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            A[i][j] = C[i][j];
        }
    }
}

vi<vi<ll>> expo(vi<vi<ll>> M, ll b){
    vi<vi<ll>> dv = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    while(b){
        if (b & 1) multi(dv, M);
        multi(M, M);
        b >>= 1;
    }
    return dv;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("loco.inp", "r", stdin); freopen("loco.out", "w", stdout);

    cin >> n >> MOD;

    vi<vi<ll>> res = expo(u, n - 1);

    multi(res, a);

    cout << res[0][0] % MOD;
}