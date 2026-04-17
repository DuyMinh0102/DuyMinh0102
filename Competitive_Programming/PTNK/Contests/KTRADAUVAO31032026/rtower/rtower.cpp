// Source: ..
// Status: Unsolved
/*
Note: ..

Solution: ..

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 31/03/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, INF = 2e9;
int n, h[N], d[N], cnt = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("rtower.inp", "r", stdin); freopen("rtower.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i];

    bool not_z = true;
    while(not_z){
        not_z = false;

        for (int i = 1; i <= n; ++i){
            if (h[i] == 0) continue;

            not_z = true;
            int mn = 2e9;
            if (i > 1) mn = min(mn, h[i - 1]);
            if (i < n) mn = min(mn, h[i + 1]);
            if (h[i] <= mn) d[i] = 1;
            else d[i] = h[i] - mn;
        }
        for (int i = 1; i <= n; ++i){
            h[i] -= d[i];
            d[i] = 0;
        }
        if (not_z) ++cnt;
    }

    cout << cnt;
}