// Source: Problems/solved/computer.jpg
// Status: Solved
/* Note: Match N system units to N monitors. Each can be VGA only, DVI only or both.
Find the maximmum number of compatible matchings.

Soluton: Greedy. Match VGA to VGA, DVI to DVI, then match the remaining VGA and DVI to the both.
Time complexity O(1).

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 06/04/2026
*/ 

#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3, b1, b2, b3;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("computer.inp", "r", stdin);
    freopen("computer.out", "w", stdout);

    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    int ans = 0, match = 0;

    match = min(a1, b1);
    ans += match;
    a1 -= match; b1 -= match;

    match = min(a2, b2);
    ans += match;
    a2 -= match; b2 -= match;

    match = min(b1, a3);
    ans += match;
    b1 -= match; a3 -= match;

    match = min(b2, a3);
    ans += match;
    b2 -= match; a3 -= match;

    match = min(a3, b3);
    ans += match;
    a3 -= match; b3 -= match;

    cout << ans;
}