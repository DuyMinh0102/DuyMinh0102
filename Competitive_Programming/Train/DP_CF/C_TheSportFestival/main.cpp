// Source: https://codeforces.com/contest/1509/problem/C
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 2005;

// Variables
int n;
ll dp[N][N];
ll a[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i][i] = 0;
    }
    sort(a + 1, a + n + 1);

    for (int l = 2; l <= n; ++l){
        for (int i = 1; i <= n; ++i){
            int j = i + l - 1;
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + a[j] - a[i];
        }
    }

    cout << dp[1][n];
}