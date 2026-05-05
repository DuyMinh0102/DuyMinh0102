#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, mx = 1;
vector<int> g[N], d(N, 1), ans;
bool vis[N] = {false};

void dfs(int u){
    vis[u] = true;

    for (int v : g[u]){
        if (d[v] < d[u] + 1){
            d[v] = d[u] + 1;
            mx = max(mx, d[v]);
            dfs(v);
        }
    }

    ans.push_back(u);
}

void topo_sort(){
    ans.clear();
    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            d[i] = 1;
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v);
    }

    topo_sort();
    memset(vis, sizeof(vis), false);

    cout << mx;
}