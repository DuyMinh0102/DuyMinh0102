#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, lg = 18;
int n, tin[N], tout[N], timer = 0, d[N] = {0}, up[N][lg], bit[N];
vector<int> g[N];
bool harvested[N] = {false};

void update(int id, int val){
    for (; id <= n; id += id & -id) bit[id] += val;
}

int query(int id){
    int cnt = 0;
    for (; id > 0; id -= id & -id) cnt += bit[id];
    return cnt;
}

void dfs(int u, int p){
    tin[u] = ++timer;
    d[u] = d[p] + 1;
    up[u][0] = p;   

    for (int i = 1; i < lg; ++i) up[u][i] = up[up[u][i - 1]][i - 1];

    for (int v : g[u]){
        if (v == p) continue;

        dfs(v, u);
    }

    tout[u] = timer;
}

bool ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int get_lca(int u, int v){
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;

    for (int i = lg - 1; i >= 0; --i){
        if (!ancestor(up[u][i], v)) u = up[u][i];
    }

    return up[u][0];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);   
    }

    dfs(1, 1);

    int cur = 1;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        int lca = get_lca(cur, x);  

        cout << query(tin[x]) << '\n';;

        if (!harvested[x]){
            harvested[x] = true;
            update(tin[x], 1);
            update(tout[x] + 1, -1);
        }
        cur = x;
    }
}