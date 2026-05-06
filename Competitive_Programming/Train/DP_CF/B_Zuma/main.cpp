// Source: https://codeforces.com/contest/607/problem/B
// Status: Solved
/*
Note: Each operation allows you to pick a palindromic subsequence and delete it from the sequence.
After that, the rest of the seq will ber merged into one seq again, without the deleted part.
Find the minimum operations needed.

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
const int N = 505;

// Variables
int n;
ll c[N];
vector<vector<ll>> dp(N, vector<ll>(N, 1e9));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
    }

    for (int i = 1; i <= n; ++i) dp[i][i] = 1;
    for (int i = 1; i < n; ++i) dp[i][i + 1] = (c[i] == c[i + 1]) ? 1 : 2;

    for (int l = 3; l <= n; ++l){
        for (int i = 1; i <= n - l + 1; ++i){
            int j = i + l - 1;

            if (c[i] == c[j]) dp[i][j] = dp[i + 1][j - 1];

            for (int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    cout << dp[1][n];
}