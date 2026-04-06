#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q;

struct DSU{
    vector<int> par, color;

    void init(int n){
        par.resize(n + 1);
        color.resize(n + 1);
        for (int i = 1; i <= n; ++i){ par[i] = i, color[i] = 0; }
    }

    int findset(int u){ 
        if (par[u] == u) return u;
        int p = par[u];
        int r = findset(p);
        color[u] ^= color[p];
        return par[u] = r;
    }

    bool uni(int u, int v){
        int pu = findset(u), pv = findset(v);

        if(pu == pv) return false;
        par[pu] = pv;
        color[pu] = color[v] ^ 1 ^ color[u];    
        return true;
    }

    string check(int u, int v){
        int pu = findset(u), pv = findset(v);
        if (pu != pv) return "DUNNO";
        int d = color[u] ^ color[v];
        if (d == 0) return "SAFE";
        return "FATAL";
    }
} Dsu;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    Dsu.init(n);

    while(q--){
        int t, u, v; cin >> t >> u >> v;

        if (t == 1){
            Dsu.uni(u, v);
        }
        else cout << Dsu.check(u, v) << '\n';
    }
}