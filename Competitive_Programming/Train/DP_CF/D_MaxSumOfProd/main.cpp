// Source: https://codeforces.com/contest/1519/problem/D
// Status: Solved
/*
Note: Reverse a single subarray of A once so that sum of (a_i * b_i) is maximize;

Solution: O(N^2), iterating through i and for each i, try it as a center of a reverse segment
Do two cases: i for odd lengthed segment and i and i + 1 of even lengthed segment.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 27/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 5005;

// Variables
int n;
ll res = 0;
ll unrevsum[N], a[N], b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        unrevsum[i] = a[i] * b[i] + unrevsum[i - 1];
    }

    for (int i = 1; i <= n; ++i){
        int l = i, r = i;
        ll cursum = 0;

        while(l >= 1 && r <= n){
            cursum += a[l]*b[r];
            if (l != r) cursum += a[r] * b[l];
            ll tmp = unrevsum[l - 1] + cursum + unrevsum[n] - unrevsum[r];
            res = max(tmp, res);

            --l;
            ++r;
        }

        if (i + 1 <= n){
            l = i;
            r = i + 1;
            cursum = 0;
            while(l >= 1 && r <= n){
                cursum += a[l]*b[r] + a[r]*b[l];
                ll tmp = unrevsum[l - 1] + cursum + unrevsum[n] - unrevsum[r];
                res = max(res, tmp);

                --l;
                ++r;
            }
        }
    }

    cout << res;
}