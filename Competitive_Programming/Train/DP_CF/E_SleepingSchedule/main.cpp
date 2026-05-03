// Source: https://codeforces.com/contest/1324/problem/E
// Status: Solved
/*
Note: A day has h hours. Vova sleeps for n times. The i-th time he sleep is exactly a_i 
or a_i - 1 hours after he last woke up. Every time, he sleeps for h hours. 
Count the amount of sleeping
time that is good (good: he starts sleeping between hours l and r).

Solution: a two dimensional dp

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 03/05/2026 (DD/MM/YYYY).
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
int n, h, l, r;
int a[N], dp[N][N];

int in_range(int x){
    if (x >= l && x <= r) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> h >> l >> r;

    for (int i = 0; i < n; ++i) cin >> a[i];    

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < h; ++j){
            if (dp[i][j] != -1){
                int u = (j + a[i]) % h, v = (j + a[i] - 1) % h;

                dp[i + 1][u] = max(dp[i + 1][u], dp[i][j] + in_range(u));
                dp[i + 1][v] = max(dp[i + 1][v], dp[i][j] + in_range(v));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) ans = max(ans, dp[n][i]);

    cout << ans;
}