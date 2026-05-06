#include <bits/stdc++.h>
using namespace std;
int n, s;
struct item{
    int w, v;
} a[105];
long long dp[105][100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> s;

    for (int i = 1; i <= n; ++i) cin >> a[i].w >> a[i].v;
    
    for (int j = 1; j <= s; ++j){
        for (int i = 1; i <= n; ++i){
            if (a[i].w <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].w] + a[i].v);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][s];
}