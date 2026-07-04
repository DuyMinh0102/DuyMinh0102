#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, q, pos = 1, id[N], sz[N];
vector<int> g[N];
ll bit[N] = {0};

void dfs(int u, int p){
    id[u] = pos++;
    sz[u] = 1;

    for (int v : g[u]){
        if (v != p){
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

void upd(int idx, ll val){
    for (int i = idx; i <= n; i += (i & -i)) bit[i] += val;
}

ll get(int idx){
    ll res = 0;
    for (int i = idx; i > 0; i -= (i & -i)) res += bit[i];

    return res;
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
        int t; cin >> t;

        if (t == 1){
            int u, v;
            cin >> u >> v;

            upd(id[u], v);
            upd(id[u] + sz[u], -v);
        }
        else{
            int u; cin >> u;

            cout << get(id[u]) << '\n';
        }
    }
}