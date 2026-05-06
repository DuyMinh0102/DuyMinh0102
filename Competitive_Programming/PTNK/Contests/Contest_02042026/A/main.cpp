// Source: ..
// Status: Solved
/*
Note: N-th fibonacci.

Solution: Matrix Multi + Matrix Expo

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 02/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1000000007;
typedef vector<vector<ll>> Matrix;
ll n;

Matrix multiply(Matrix A, Matrix B) {
    Matrix C(2, vector<ll>(2, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, ll p) {
    Matrix res = {{1, 0}, {0, 1}}; 
    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    
    Matrix T = {{1, 1}, {1, 0}};
    Matrix Tn = power(T, n);
    
    cout << Tn[0][1];
}