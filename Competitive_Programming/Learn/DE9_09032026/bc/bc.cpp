// Source: Problems/DE09.pdf
// Status: Solved
/* 
Note: You are given a tree, and a target that starts moving from vertex 1. If the target reaches a leaf, you lose.
You can choose to place a guard at any vertex. A guard can move to an adjacent vertex in one second. 
You win if you can catch the target before it reaches a leaf. What is the minimum number of guards you need to guarantee a win?

Solution: DP on tree
We calculate the distance from each vertex to the nearest leaf. And from the root to each vertex. 
If the distance from the root to a vertex is greater than the distance from that vertex to the nearest leaf, 
we need to place a guard at that vertex.

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 09/03/2026
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N], l_dist(N, 300000);
int d[N] = {0}, n;

void dfs(int u, int p){
    d[u] = d[p] + 1;

    for (int v : g[u]){
        if (v != p){
            dfs(v, u);
            l_dist[u] = min(l_dist[u], l_dist[v] + 1);
        }
    }

    if (g[u].size() == 1 && u != 1) l_dist[u] = 0;
}

int solve(int u, int p){
    int res = 0;
    if (d[u] > l_dist[u]) return 1;

    for (int v : g[u]){
        if (v != p) res += solve(v, u);
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bc.inp", "r", stdin); freopen("bc.out", "w", stdout);

    cin >> n;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0);

    cout << solve(1, 0);
}