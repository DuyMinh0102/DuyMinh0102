// Source: https://codeforces.com/contest/1288/problem/C
// Status: Solved
/*
Solution: Let dp[i][j] be the amount of valid non-decreasing of length i that ends with j
Base case: i = 1 => dp[i][j] = 1 for all 1 <= j <= n
dp[i][j] = sum(dp[i - 1][k]) for all 1 <= k <= j
Which basically is dp[i][j] = dp[i][j - 1] + dp[i - 1][j]

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
const ll MOD = 1e9 + 7;
const int N = 1005;

// Variables
int n, m;
vector<vector<ll>> dp(25, vector<ll>(N, 0));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int j = 1; j <= n; ++j){
        dp[1][j] = 1;
    }

    for (int i = 2; i <= 2*m; ++i){
        for (int j = 1; j <= n; ++j){
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    ll res = 0;
    for (int j = 1; j <= n; ++j) res = (res + dp[2*m][j]) % MOD;

    cout << res;
}