// Source: Problems/solved/captoc.jpg
// Status: Solved
/* 
Note: You have to distribute X days of studying across N subjects to maximize your score.
A matrix A_ij is given where A_ij is the score you get it you spend j days to study subject i.
Solution: A Bounded knapsack problem
For every subject:
    For every possible number of days to study:
        For every possible number of days to study the previous subjects:
            Update the maximum score.
Time complexity: O(N.X^2)

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 30/03/2026
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, x, a[N][N];
int dp[N][N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    freopen("captoc.inp", "r", stdin); freopen("captoc.out", "w", stdout);

    cin >> n >> x;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= x; ++j) cin >> a[i][j];
    }

    for (int i = 0; i <= x; ++i) dp[0][i] = 0;

    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= x; ++j){
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= j; ++k){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[i][k]);
            }
        }
    }

    cout << dp[n][x];
}