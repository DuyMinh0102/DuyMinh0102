// Source: https://codeforces.com/contest/1555/problem/D
// Status: Solved
/*
Note: Given M queries, determine the minimum amount of characters that needs to change in order for the substr to not
contain any palindrome substr longer than 1.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 06/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
#define vt vector
const int N = 2e5 + 5;

// Variables
int n, m;
string s;
vt<vt<ll>> dp(6, vt<ll>(N, 0));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> s;

    vt<string> pattern{ "abc", "acb", "bac", "bca", "cab", "cba" };

    for (int k = 0; k < 6; ++k){
        for (int i = 0; i < n; ++i){
            dp[k][i + 1] = dp[k][i] + (ll)(s[i] != pattern[k][i % 3]);
        }
    }

    while(m--){
        int l, r; cin >> l >> r;

        ll cost = 1e9;
        for (int k = 0; k < 6; ++k){
            cost = min(cost, dp[k][r] - dp[k][l - 1]);
        }

        cout << cost << '\n';
    }
}