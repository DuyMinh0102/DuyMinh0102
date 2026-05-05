#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int g[21][21], dp[1 << 20][20], n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; ++u) {
            if (dp[mask][u] == INF) continue;

            for (int v = 0; v < n; ++v) {
                if (!(mask & (1 << v))) {
                    int nxt = mask | (1 << v);
                    dp[nxt][v] = min(dp[nxt][v], dp[mask][u] + g[u][v]);
                }
            }
        }
    }

    int ans = INF, mask = (1 << n) - 1;
    for (int i = 1; i < n; ++i) {
        if (dp[mask][i] != INF) {
            ans = min(ans, dp[mask][i] + g[i][0]);
        }
    }

    if (n == 1) ans = 0;

    cout << ans;

    return 0;
}