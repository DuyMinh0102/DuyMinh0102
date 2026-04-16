// Source: Problems/BT_20260226.pdf
// Status: Unsolved.
/*
Note: I don't even understand the problem.

Solution:

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 26/02/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e6 + 5;
int n, V, E, par[N];
struct edge{
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const edge& other){
        return w > other.w;
    }
};
vector<edge> e;
vector<pair<int, ll>> g[N];

int findpar(int u){
    return (u == par[u]) ? u : findpar(par[u]);
}

bool uni(int u, int v){
    findpar(u); findpar(v);

    if (u == v) return false;
    par[v] = u;
    return true;
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("travel.inp", "r", stdin); freopen("travel.out", "w", stdout);

    cin >> V >> E >> n;

    for (int i = 0; i < E; ++i){
        int u, v, w; cin >> u >> v >> w;

        e.push_back(edge(u, v, w));
    }

    sort(e.begin(), e.end());

    for (int i = 0; i < e.size(); ++i){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (uni(u, v)){
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }

    
}