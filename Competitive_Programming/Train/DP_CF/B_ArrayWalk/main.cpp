// Source: https://codeforces.com/contest/1389/problem/B
// Status: Solved
/*
Note: The greedy logic must account for two path types: 
- paths that end on a right move (fully balanced bounces) 
- paths that end on a left move.
Solution: Iterate over the number of left moves (j). 
For each j, evaluate the max score if all j moves are full bounces, AND the max score if j-1 moves are bounces 
and the sequence ends with a left move.

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
            
            int lim1 = 1 + k - 2 * j;
            if (lim1 >= 1){
                ll sum = 0, best_pair = 0;
                for (int i = 1; i <= lim1; ++i){
                    sum += a[i];
                    if (i < lim1) best_pair = max(best_pair, a[i] + a[i + 1]);
                }
                res = max(res, sum + j * best_pair);
            }

            if (j > 0){
                int lim2 = 2 + k - 2 * j; 
                if (lim2 >= 2 && lim2 <= n){
                    ll sum = 0, best_pair = 0;
                    for (int i = 1; i <= lim2; ++i){
                        sum += a[i];
                        if (i < lim2) best_pair = max(best_pair, a[i] + a[i + 1]);
                    }
                    res = max(res, sum + (j - 1) * best_pair + a[lim2 - 1]);
                }
            }
        }

        cout << res << '\n';
    }
    return 0;
}