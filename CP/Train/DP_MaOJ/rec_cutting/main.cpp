#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int a, b;
int dp[505][505] = {{INF}};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> a >> b;

    for (int i = 0; i <= 500; ++i){
        for (int j = 0; j <= 500; ++j) dp[i][j] = INF;
    }

    if (a == b) cout << 0;
    else{
        for (int i = 1; i <= a; ++i){
            for (int j = 1; j <= b; ++j){
                if (i == j) dp[i][j] = 0;
                else{
                    for (int k = 1; k < i; ++k) dp[i][j] = min(dp[k][j] + dp[i - k][j] + 1, dp[i][j]);
                    for (int k = 1; k < j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }   
        }
    }

    cout << dp[a][b];
}