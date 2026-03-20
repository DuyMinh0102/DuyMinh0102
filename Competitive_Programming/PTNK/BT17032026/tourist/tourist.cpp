#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, lg = 18;
int n, up[N][lg], d[N] = {0};
vector<int> g[N];

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

ll path(int u, int v){
    ll lca = get_lca(u, v);

    return (d[u] + d[v] - 2*d[lca] + 1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("tourist.inp", "r", stdin); freopen("tourist.out", "w", stdout);

    cin >> n;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    d[0] = -1;
    dfs(1, 0);

    ll res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 2; j * i <= n; ++j){
            res += path(i, i*j);
        }
    }

    cout << res;
}