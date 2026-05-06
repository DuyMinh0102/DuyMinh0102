#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, m, par[N], sz[N];
vector<int> g[N];
struct edge{
    ll u, v, w, id;
    edge(int _u, int _v, int _w, int _id): u(_u), v(_v), w(_w), id(_id) {}
    bool operator<(const edge& other){
        return w < other.w;
    }
};
vector<edge> e;

ll findset(int u){ return (u == par[u]) ? u : par[u] = findset(par[u]); }

void uni(int u, int v){
    u = findset(u); v = findset(v);

    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
        e.push_back(edge(u, v, w, i));
    }
    sort(e.begin(), e.end());

    for (int i = 1; i <= n; ++i){ par[i] = i; sz[i] = 1; }

    vector<bool> res(m, '0');

    int i = 0;
    while(i < m){
        ll w0 = e[i].w, j = i;

        while(j < m && e[j].w == w0) ++j;
        for (int k = i; k < j; ++k){
            ll ru = findset(e[k].u),
            rv = findset(e[k].v);
            if (ru != rv) res[e[k].id] = (res[e[k].id] + 1) % 1;
        }

        for (int k = i; k < j; ++k){
            uni(e[k].u, e[k].v);
        }
        i = j;
    }
    for (bool i : res) cout << (!i);
}