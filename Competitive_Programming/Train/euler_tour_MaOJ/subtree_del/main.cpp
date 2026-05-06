#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, k, val[N], pos[N], idx = 0, sz[N];
vector<int> g[N];
ll t[N];

void dfs(int u, int p){
    pos[u] = ++idx;
    sz[u] = 1;
    t[u] = val[u];

    for (int v : g[u]){
        if (v != p){
            dfs(v, u);
            sz[u] += sz[v];
            t[u] += t[v];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) cin >> val[i];

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i){
        int id = pos[i];
        
    }
}