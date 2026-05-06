#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 505, INF = 1e18;
int n, m, q;
vector<vector<ll>> dist(N, vector<ll>(N, INF));

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) dist[i][i] = 0;

    for (int i = 0; i < m; ++i){
        ll u, v, w; cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (dist[i][k] != INF && dist[k][j] != INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while(q--){
        int u, v; cin >> u >> v;

        if (dist[u][v] == INF) cout << -1 << '\n';
        else cout << dist[u][v] << '\n';
    }
}