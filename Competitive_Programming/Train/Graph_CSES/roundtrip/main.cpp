#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, cs, ce;
vector<int> g[N], par(N);
bool vis[N];

bool dfs(int u, int p){
    par[u] = p;
    vis[u] = true;
    for (int v : g[u]){
        if (v != p){
            if (vis[v]){
                cs = v;
                ce = u;
                return true;
            }
            if (!vis[v] && dfs(v, u)) return true;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i){
        if (!vis[i]){
            if (dfs(i, 0)){
                vector<int> res;
                res.push_back(cs);
                for (; ce != cs; ce = par[ce]){
                    res.push_back(ce);
                }
                res.push_back(cs);
                cout << res.size() << '\n';
                for (int i : res) cout << i << ' ';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
}