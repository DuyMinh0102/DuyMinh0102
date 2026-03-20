#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> g[N];
bool vis[N];
vector<bool> color(N, false);

bool bfs(int s){
    queue<pair<int, int>> q;

    q.push({s, 1});
    color[s] = 1;

    while(!q.empty()){
        int u = q.front().first;
        q.pop();

        vis[u] = true;
        for (int v : g[u]){
            if (vis[v]){
                if (color[v] == color[u]) return false;
                else continue;
            }
            color[v] = !color[u];
            q.push({v, color[v]});
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool ans = true;

    for (int i = 1; i <= n; ++i){
        if (!vis[i]) ans = ans && bfs(i);
    }

    if (ans) cout << "YES";
    else cout << "NO";
}