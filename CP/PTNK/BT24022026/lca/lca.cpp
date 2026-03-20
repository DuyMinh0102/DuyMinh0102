#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, lg = 18;
int n, q, up[N][lg], d[N];
vector<int> g[N];

void dfs(int u, int p){
    up[u][0] = p;

    for (int i = 1; i < lg; ++i) up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : g[u]){
        if (v != p){
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
}

int get(int u, int v){
    if (d[u] < d[v]) swap(u, v);

    int df = d[u] - d[v];
    for (int i = 0; i < lg; ++i){
        if ((df >> i) & 1) u = up[u][i];
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

    freopen("lca.inp", "r", stdin);
    freopen("lca.out", "w", stdout);

    cin >> n;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0);

    cin >> q;

    while(q--){
        int u, v; cin >> u >> v;

        cout << get(u, v) << '\n';
    }
}   