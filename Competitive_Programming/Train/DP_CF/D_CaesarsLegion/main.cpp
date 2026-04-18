// Source: https://codeforces.com/contest/118/problem/D
// Status: Solved
/*
Note: Caesar has n_1 footmen and n_2 horsemen. Count the amount of ways to arrange them in a line so that
there are no more than k_1 footmen standing next to each other and no more than k_2 for horsemen

Solution: dp[i][j][t] (where t is the type: 0 is footmen, 1 is horsemen), means you have placed i footmen and j horsemen so far,
the current one is of type t.
To find dp[i][j][0] and assure that no more than k1 footmen stands next to each other,
we loop from k = 1 to min(i, k_1): the total amount of ways to have a horsemen standing at position i - k
Same with dp[i][j][1], where we go from k = 1 to min(j, k2): the total amount of ways to have a footmen standing at position i - k.
max k is k1 or k2, the furthest backwards it can go is k1 or k2 positions, which assures that the rule will not be broken

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 18/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long
const int N = 105;
const ll MOD = 100000000;

// Variables
int n1, n2, k1, k2;
ll dp[N][N][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n1 >> n2 >> k1 >> k2;

    for (int i = 1; i <= k1; ++i) dp[i][0][0] = 1;
    for (int i = 1; i <= k2; ++i) dp[0][i][1] = 1;

    for (int i = 1; i <= n1; ++i){
        for (int j = 1; j <= n2; ++j){
            for (int k = 1; k <= min(i, k1); ++k){
                dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
            }

            for (int k = 1; k <= min(j, k2); ++k){
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
            }
        }
    }

    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD;
}