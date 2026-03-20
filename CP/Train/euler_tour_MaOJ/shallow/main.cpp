#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, d[N], order[N], pos = 1;
vector<int> g[N];

void dfs(int u, int p){
    order[u] = pos++;

    for (int v : g[u]){
        if (v != p){
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
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
        int k; cin >> k;

        int mn = n, mx = 1, mn_u, mx_u;
        for (int i = 0; i < k; ++i){
            int u; cin >> u;
            if (order[u] < mn){
                mn = order[u];
                mn_u = u;
            }
            
            if (order[u] > mx){
                mx = order[u];
                mx_u = u;
            }
        }

        cout << mn_u << ' ' << mx_u << '\n';
    }
}