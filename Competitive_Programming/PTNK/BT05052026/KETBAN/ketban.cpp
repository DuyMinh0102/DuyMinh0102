// Source: no_source
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 05/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long
#define pb push_back
const int N = 1e5 + 5;
struct DSU{
    int n;
    vector<int> par, sz;
    int comp;

    DSU(int n) : n(n), par(n), sz(n, 1), comp(n) {
        for (int i = 0; i < n; ++i){
            par[i] = i;
        }
    }

    void reset(){
        for (int i = 0; i < n; ++i) par[i] = i;
        fill(sz.begin(), sz.end(), 1);
        comp = n;
    }

    int find(int u){
        return (u == par[u]) ? u : par[u] = find(par[u]);
    }

    bool uni(int u, int v){
        u = find(u);
        v = find(v);

        if (u == v) return false;

        if (sz[u] < sz[v]) swap(u, v);

        par[v] = u;
        sz[u] += sz[v];
        --comp;

        return true;
    }

    bool connect(int u, int v){ return find(u) == find(v);}
};

struct invit{
    int u, v, id;
    invit() {}

    invit(int _u, int _v, int _id): u(_u), v(_v), id(_id) {}
};
struct query{
    int u, v, id;
    query() {}

    query(int _u, int _v, int _id): u(_u), v(_v), id(_id) {}
};

// Variables
int n, m, q;
vector<invit> in;
vector<query> Q;
vector<int> L, R, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        in.pb(invit(u, v, i));
    }

    for (int i = 0; i < q; ++i){
        int u, v; cin >> u >> v;

        Q.pb(query(u, v, i));
    }

    DSU dsu(n + 1);
    L.resize(q, 0); R.resize(q, m - 1); ans.resize(q, -1);

    bool c = true;
    while(c){
        c = false;
        vector<int> check[m + 1];

        for (int i = 0; i < q; ++i){
            if (L[i] <= R[i]){
                int mid = L[i] + ((R[i] - L[i]) >> 1);
                check[mid].push_back(i);
                c = true;
            }
        }

        if (!c) break;

        dsu.reset();

        for (int i = 0; i < m; ++i){
            dsu.uni(in[i].u, in[i].v);

            for (int id : check[i]){
                if (dsu.connect(Q[id].u, Q[id].v)){
                    ans[id] = i + 1;
                    R[id] = i - 1;
                }
                else L[id] = i + 1;
            }
        }
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}