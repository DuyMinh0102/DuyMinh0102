// Source: 
// Status:
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 04/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 105, INF = 1e9;

// Variables
int n, m;
ll dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("hcn.inp", "r", stdin);
    freopen("hcn.out", "w", stdout);

    while(cin >> m >> n){
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                dp[i][j] = INF;
            }
        }

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if (i == j) dp[i][j] = 0;
                else{
                    for (int k = 1; k <= i; ++k) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);

                    for (int k = 1; k <= j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }

        cout << dp[m][n] + 1 << '\n';
    }
}