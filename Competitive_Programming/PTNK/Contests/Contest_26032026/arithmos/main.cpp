// Source: ..
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 26/03/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, t, a;

ll f(ll x) {
    ll r = x;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            r -= r / i;
        }
    }
    if (x > 1) r -= r / x;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    if (!(cin >> n)) return 0;

    t = n;
    a = 0;

    for (ll i = 2; i * i <= t; ++i) {
        if (t % i == 0) {
            a += f(n / i);
            while (t % i == 0) t /= i;
        }
    }

    if (t > 1) {
        a += f(n / t);
    }

    cout << a << '\n';

    return 0;
}