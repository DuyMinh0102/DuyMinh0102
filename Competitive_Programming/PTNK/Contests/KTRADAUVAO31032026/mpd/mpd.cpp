#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 21, P = 1000000;
int n, m, p, a[N][N];
ll dp[N][N][P];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("mpd.inp", "r", stdin); freopen("mpd.out", "w", stdout);

    cin >> n >> m >> p;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    /*    
    for (int i = 0; i <= n; ++i) dp[i][0][0] = 1;
    for (int i = 0; i <= m; ++i) dp[0][i][0] = 1;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            for (int k = 0; k < P; ++k){
                dp[i][j][k] = dp[i - 1][j][(k - a[i][j]) % P] + dp[i][j - 1][(k - a[i][j]) % P] + 2;
            }
        }
    }
    */
}