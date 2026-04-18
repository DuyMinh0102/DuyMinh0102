// Source: https://codeforces.com/contest/1336/problem/A
// Status: Solved
/*
Note: Given a tree of $n$ nodes (root at node 1), select exactly $k$ nodes as industry cities. 
The remaining $n - k$ nodes are tourism cities. Maximize the total "happiness," 
defined as the sum of tourism cities encountered on the path from each industry city to the root.

Solution: Prioritizes leaf nodes to be industrial.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 18/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long
const int N = 2e5 + 5;

// Variables
ll n, k, d[N], sz[N], w[N];
vector<int> g[N];

void dfs(int u, int p){
    sz[u] = 1;
    d[u] = d[p] + 1;

    for (int v : g[u]){
        if (v != p){
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    w[u] = d[u] - sz[u] + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> n >> k;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }

    d[0] = -1;
    dfs(1, 0);
    sort(w + 1, w + n + 1, greater<int>());

    ll sum = 0;
    for (int i = 1; i <= k; ++i) sum += w[i];
    cout << sum;
}