#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, mx = 0, dp[N][26];
vector<int> g[N], topo;
char val[N];
bool vis[N] = {false};

void dfs(int u){
    vis[u] = true;

    for (int v : g[u]){
        if (!vis[v]) dfs(v);
    }

    topo.push_back(u);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) cin >> val[i];
    
    for (int i = 0; i < m; ++i){
        int u, v; cin >>u >> v;

        g[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            dfs(i);
        }
    }

    reverse(topo.begin(), topo.end());

    for (int u : topo){
        int id = val[u] - 'a';
        dp[u][id] = max(dp[u][id], 1);

        for (int v : g[u]){
            for (int i = 0; i < 26; ++i){
                dp[v][i] = max(dp[v][i], dp[u][i] + ((val[v] - 'a') == i));
                mx = max(mx, dp[v][i]);
            }
        }
    }

    cout << mx;
}