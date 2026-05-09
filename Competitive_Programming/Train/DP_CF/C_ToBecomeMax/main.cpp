// Source: https://codeforces.com/contest/1856/problem/C
// Status: Solved 
/*
Note: ..

Solution: ..

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 26/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 1e3 + 5;

// Variables
int t, n, k;
int a[N];

bool check(int target){
    for (int i = 1; i <= n; ++i){
        int cost = 0;
        bool found = false;

        for (int j = i; j <= n; ++j){
            int req = target - j + i;

            if (a[j] >= req){
                found = true;
                break;
            }

            if (j == n) break;

            cost += (req - a[j]);

            if (cost > k) break;
        }

        if (found && cost <= k) return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    
    while(t--){
        cin >> n >> k;

        int mx = 0;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        int lo = mx, hi = mx + k;
        int res = lo;
        while(lo <= hi){
            int mid = lo + ((hi - lo) >> 1);

            if (check(mid)){
                res = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        cout << res << '\n';
    }
}