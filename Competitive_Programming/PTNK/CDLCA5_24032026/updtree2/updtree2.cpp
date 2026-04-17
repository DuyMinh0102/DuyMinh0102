// Source: Ilostthesauce
// Status: Solved
/*
Note: .. 
 
Solution: ..

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 24/03/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, lg = 18;
ll n, q, p, up[N][lg], d[N], diff[N] = {0}, edge[N] = {0}, pref[N] = {0};
vector<int> g[N];

void dfs(int u, int p){
    up[u][0] = p;
    d[u] = d[p] + 1;

    for (int i = 1; i < lg; ++i) up[u][i] = up[up[u][i- 1]][i - 1];
    
    for (int v : g[u]){
        if (p == v) continue;

        dfs(v, u);
    }
}

void dfs_diff(int u, int p){
    edge[u] = diff[u];
    for (int v : g[u]){
        if (v == p) continue;
        dfs_diff(v, u);
        edge[u] += edge[v];
    }
}

void dfs_p(int u, int p, ll cursum){
    pref[u] = cursum;
    for (int v : g[u]){
        if (v == p) continue;
        dfs_p(v, u, cursum + edge[v]);
    }
}

int get_lca(int u, int v){
    if (d[u] < d[v]) swap(u, v);

    int dist = d[u] - d[v];
    for (int i = 0; i < lg; ++i) if ((dist >> i) & 1) u = up[u][i];

    if (u == v) return u;

    for (int i = lg - 1; i >= 0; --i){
        if (up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void add(int u, int v, ll val){
    int lca = get_lca(u, v);
    diff[u] += val;
    diff[v] += val;
    diff[lca] -= 2*val;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("updtree2.inp", "r", stdin); freopen("updtree2.out", "w", stdout);

    cin >> n >> q >> p;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0);  

    while(q--){
        int A, B, C, D; cin >> A >> B >> C >> D;

        add(A, B, 1);

        int lca_AB = get_lca(A, B),
        lca_CD = get_lca(C, D);

        vector<int> l = {get_lca(A, C), get_lca(A, D), get_lca(B, C), get_lca(B, D)};
        sort(l.begin(), l.end(), [](int x, int y){ return d[x] > d[y];});

        int u =  l[0], v = l[1];

        if (d[u] >= max(d[lca_AB], d[lca_CD])) add(u, v, -1);
    }

    dfs_diff(1, 0);
    dfs_p(1, 0, 0);

    for (int i = 0; i < p; ++i){
        int e, f; cin >> e >> f;

        int lca = get_lca(e, f);

        ll ans = pref[e] + pref[f] - 2 * pref[lca];
        cout << ans << '\n';
    }
}