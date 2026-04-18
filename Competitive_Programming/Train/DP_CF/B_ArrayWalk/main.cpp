// Source: https://codeforces.com/contest/1389/problem/B
// Status: Solved
/*
Note: 

Solution: 

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 18/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long
const int N = 1e5 + 5;

// Variables
int t, n, k, z;
ll a[N], pref[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--){
        cin >> n >> k >> z;

        for (int i = 1; i <= n; ++i) cin >> a[i];

        ll res = 0;

        for (int j = 0; j <= z; ++j){
            int lim = 1 + k - 2*j;
            if (lim < 1) continue;

            ll sum = 0, best_pair = 0;

            for (int i = 1; i <= lim; ++i){
                sum += a[i];
                if (i < lim) best_pair = max(best_pair, a[i] + a[i + 1]);
            }

            sum += j * best_pair;
            res = max(res, sum);
        }

        cout << res << '\n';
    }
}