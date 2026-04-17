// Source: ..
// Status: Solved?
/*
Note: ..

Solution: ..

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 23/03/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("pier.inp", "r", stdin); freopen("pier.out", "w", stdout);

    cin >> n >> a >> b;

    ll m = (a + b * n) / (a + b);

    ll diff = abs(a * (m - 1) - b * (n - m));
    ll x = m - 1, y = m + 1;
    
    ll diff_x = abs(a * (x - 1) - b * (n - x)),
    diff_y = (a * (y - 1) - b * (n - y));

    if (diff_x < diff) m = x;
    if (diff_y < diff) m = y;

    if (m == 1) ++m;
    if (m == n) --m;

    cout << m;
}   