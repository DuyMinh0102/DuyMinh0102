#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, q, par[N], sz[N], ans[N];
struct edge{
    int u, v;
};
vector<edge> e;
bool removed[N];

struct query{
    int id, u;
} Q[N];

int findr(int u){
    return (u == par[u]) ? u : par[u] = findr(par[u]);
}

void uni(int u, int v){
    u = findr(u); v = findr(v);

    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        e.push_back({u, v});
    }

    for (int i = 0; i < q; ++i){
        cin >> Q[i].id >> Q[i].u;
        removed[Q[i].id - 1] = true;
    }

    for (int i = 0; i < m; ++i){
        if (!removed[i]){
            uni(e[i].u, e[i].v);
        }
    }

    for (int i = q - 1; i >= 0; --i){
        ans[i] = sz[findr(Q[i].u)];
        int id = Q[i].id - 1;
        uni(e[id].u, e[id].v);
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}