// Source: Ilostthesauce
// Status: Solved
/*
Note: Find the lowest common ancestor of two nodes.

Solution: There's only one query, and the constraints are small (if I remember correctly, since Ilostthesauce), I just brute force it.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 24/02/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, k, par[N], d[N];
vector<int> g[N];

void dfs(int u, int p){
    par[u] = p;
    
    for (int v : g[u]){
        if (v != p){
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("ances.inp", "r", stdin); freopen("ances.out", "w", stdout);

    cin >> n >> k;

    int u, v;
    for (int i = 1; i < n; ++i){
        cin >> u >> v;
        
        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(k, 0);

    cin >> u >> v;

    if (d[u] < d[v]) swap(u, v);
    
    while(d[u] < d[v]) u = par[u];

    while(u != v){
        u = par[u];
        v = par[v];
    }

    cout << u;
}