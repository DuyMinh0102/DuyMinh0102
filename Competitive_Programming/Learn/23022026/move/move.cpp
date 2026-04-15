// Source: Problems/MOVE.jpg, from a teacher of mine
// Status: Solved
/* Note: Given an undirected graph with n (n <= 200) vertices, each node has a temperature t_i.
Find a path from A to B that the maximum difference of temperature between two vertices is minimized.
Output -1 if no path from A to B.
Solution: Djikstra Algorithm.

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 23/02/2026
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 205, INF = 1e9;
int n, a, b, t[N], dist[N];
vector<int> g[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    freopen("move.inp", "r", stdin);
    freopen("move.out", "w", stdout);

    cin >> n >> a >> b;
    
    for (int i = 1; i <= n; ++i){
        cin >> t[i];
        dist[i] = INF;
    }
    
    int u, v;
    while (cin >> u >> v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[a] = 0;
    pq.push({0, a});
    
    while (!pq.empty()) {
        int d = pq.top().first,
            u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        if (u == b) break; 
        
        for (int nxt : g[u]) {
            int weight = abs(t[u] - t[nxt]),
            mx_diff = max(d, weight);
            
            if (mx_diff < dist[nxt]) {
                dist[nxt] = mx_diff;
                pq.push({mx_diff, nxt});
            }
        }
    }
    
    if (dist[b] == INF) cout << -1 << '\n';
    else cout << dist[b] << '\n';
    
    return 0;
}