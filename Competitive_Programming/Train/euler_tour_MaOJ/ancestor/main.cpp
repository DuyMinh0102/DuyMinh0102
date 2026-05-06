#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, lg = 18;
int n, q, up[N][lg], depth[N];
vector<int> g[N];

void dfs(int u, int p){
    up[u][0] = p;

    for (int i = 1; i < lg; ++i) up[u][i] = up[up[u][i - 1]][i- 1];

    for (int v : g[u]){
        if (v != p){
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int get(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0);

    while(q--){
        int u, v; cin >> u >> v;

        int lca = get(u, v);

        if (lca == u) cout << "MA\n";
        else if (lca == v) cout << "RI\n";
        else cout << "SA\n";
    }
}