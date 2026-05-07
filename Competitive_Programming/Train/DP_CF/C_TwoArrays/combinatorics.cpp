// Source: https://codeforces.com/contest/1288/problem/C
// Status: Solved
/*
Solution: Using Stars and Bars to solve

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 06/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const ll MOD = 1e9 + 7;

// Variables
int n, m;

ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if (b & 1) res = (a * res) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll r){
    if (n < r) return 0;
    if (r == 0) return 1;

    ll num = 1, den = 1;

    for (ll i = 0; i < r; ++i){
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }

    return (num * power(den, MOD - 2)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    cout << (ll)(C(n + 2 * m - 1, 2 * m));
}