#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int t, n, k;
vector<int> g[N], deg(N, 0);
bool vis[N] = {false};

void reset(){
    for (int i = 1; i <= n; ++i){
        g[i].clear();
        vis[i] = false;
        deg[i] = 0;
    }
}

void solve(){
    cin >> n >> k;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    queue<pair<int, int>> q;

    for (int i = 1; i <= n; ++i){
        deg[i] = g[i].size();
        if (deg[i] <= 1) q.push({i, k});
    }

    while(!q.empty()){
        int u = q.front().first, l = q.front().second;
        q.pop();

        if (vis[u] || l == 0) continue;
        
        vis[u] = true;
        for (int v : g[u]){
            --deg[v];
            if (deg[v] == 1) q.push({v, l - 1});
        }
    }

    int left = 0;
    for (int i = 1; i <= n; ++i){
        if (!vis[i]) ++left;
    }

    cout << left << '\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        solve();
        reset();
    }
}