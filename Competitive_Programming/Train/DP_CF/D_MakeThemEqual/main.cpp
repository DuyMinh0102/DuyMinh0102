// Source: https://codeforces.com/contest/1633/problem/D
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 25/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 1e3 + 5;
const ll INF = 1e9;

// Variables
int t, n, k;
int b[N], c[N], cost[N];
ll dp[N][12005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cost[1] = 0;
    for (int i = 2; i <= 1000; ++i) cost[i] = INF;

    for (int i = 1; i <= 1000; ++i){
        for (int x = 1; x <= i; ++x){
            int nxt = i + (i / x);

            if (nxt <= 1000) cost[nxt] = min(cost[nxt], cost[i] + 1);
        }
    }

    cin >> t;

    while(t--){
        cin >> n >> k;
        k = min(12000, k);
        for (int i = 1; i <= n; ++i){
            cin >> b[i];
            for (int j = 1; j <= k; ++j) dp[i][j] = 0;
        }
        for (int i = 1; i <= n; ++i) cin >> c[i];   

        for (int i = 1; i <= n; ++i){
            for (int j = 0; j <= k; ++j){
                dp[i][j] = dp[i - 1][j];

                if (j >= cost[b[i]]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[b[i]]] + c[i]);
                }
            }
        }

        cout << dp[n][k] << '\n';
    }
}