#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a, b;
vector<int> g[N];
vector<vector<int>> d(N, vector<int>(2, -1)); 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> a >> b;

    for (int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v); 
        g[v].push_back(u);
    }

    queue<pair<int, int>> q;

    d[a][0] = 0;
    q.push({a, 0});

    while(!q.empty()){
        int u = q.front().first;
        int p = q.front().second; 
        q.pop();

        for (int v : g[u]){
            int next_p = 1 - p; 

            if (d[v][next_p] == -1){
                d[v][next_p] = d[u][p] + 1;
                q.push({v, next_p});
            }
        }
    }

    cout << ((d[b][0] == -1) ? -1 : (d[b][0] / 2));
    
    return 0;
}