// Source: https://codeforces.com/contest/276/problem/D
// Status: Solved
/*
Note: Within a pair of [L; R], choose two number A and B so that A^B is maximize.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 05/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 
#define bit_st(x, i) ((x & (1LL << i)) > 0)

// Config
#define pb push_back
#define ll long long

// Variables
ll l, r;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> l >> r;

    if (l == r){
        cout << 0;
        return 0;
    }

    int len = 0;
    ll tmp = 1;
    while(tmp < r){
        tmp *= 2;
        ++len;
    }

    for (ll i = len; i >= 0; --i){
        if ((bit_st(r, i) != bit_st(l, i))){
            ll res = 0;
            for (ll j = i; j >= 0; --j){
                res |= (1LL << j);
            }
            cout << res;
            break;
        }
    }
}