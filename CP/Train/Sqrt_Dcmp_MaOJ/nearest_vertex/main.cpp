#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, lg = 17;
int n, q, sz, dist[225][N], heavy_id[N], id = 0, val[N], freq[N] = {0}, up[N][lg], d[N];
vector<int> g[N], pos[N];

void dfs(int u, int p){
    up[u][0] = p;
    d[u] = d[p] + 1;
    for (int i = 1; i < lg; ++i) up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : g[u]){
        if (v == p) continue;

        dfs(v, u);
    }
}

int get_lca(int u, int v){
    if (d[u] < d[v]) swap(u, v);

    int diff = d[u] - d[v];
    for (int i = 0; i < lg; ++i){
        if ((diff >> i) & 1) u = up[u][i];
    }

    if (u == v) return u;

    for (int i = lg - 1; i >= 0; --i){
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }

    return up[u][0];
}

int distance(int u, int v){
    int lca = get_lca(u, v);

    return d[u] + d[v] - 2*d[lca];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(heavy_id, -1, sizeof(heavy_id));

    cin >> n >> q;

    sz = sqrt(n);

    for (int i = 1; i <= n; ++i){
        cin >> val[i];
        freq[val[i]]++;
    }

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        
        g[u].push_back(v); g[v].push_back(u);
    }

    d[0] = 0;
    dfs(1, 0);

    for (int i = 1; i <= n; ++i){
        if (freq[i] >= sz){
            heavy_id[i] = ++id;
            memset(dist[heavy_id[i]], -1, sizeof(dist[heavy_id[i]]));
        }
    }

    for (int i = 1; i <= n; ++i){
        if (freq[val[i]] < sz){
            pos[val[i]].push_back(i);
        }
    }

    for (int x = 1; x <= n; ++x){
        if (heavy_id[x] != -1){
            int id = heavy_id[x];
            queue<int> qu;

            for (int i = 1; i <= n; ++i) if (val[i] == x) {dist[id][i] = 0; qu.push(i);}

            while(!qu.empty()){
                int u = qu.front();
                qu.pop();

                for (int v : g[u]){
                    if (dist[id][v] == -1){
                        dist[id][v] = dist[id][u] + 1;
                        qu.push(v);
                    }
                }
            }
        }
    }

    while(q--){
        int u, x; cin >> u >> x;

        int ans = N;
        if (heavy_id[x] == -1){
            for (int v : pos[x]){
                ans = min(ans, distance(u, v));
            }
        }
        else ans = dist[heavy_id[x]][u];

        if (ans == N || ans == -1) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}