// Source: https://codeforces.com/contest/1373/problem/D
// Status: Solved
/*
Note: Reverse a contiguous subarray of A so that the sum on the even indices are maximize

Solution: do Kadane on possible gains (O(N) two times) then determine the max

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
const int N = 2e5 + 5;

// Variables
int t, n;
ll sum = 0, res = 0;
ll a[N], d1 = 0, d2 = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--){
        sum = d1 = d2 = 0;
        cin >> n;

        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            if (i & 1) sum += a[i];
        }

        ll tmp = 0;
        for (int i = 1; i < n; i += 2){
            tmp = max(a[i + 1] - a[i], tmp + a[i + 1] - a[i]);
            d1 = max(d1, tmp);
        }

        tmp = 0;
        for (int i = 2; i < n; i += 2){
            tmp = max(a[i] - a[i + 1], tmp + a[i] - a[i + 1]);
            d2 = max(d2, tmp);
        }

        cout << sum + max({0LL, d1, d2}) << '\n';
    }
}