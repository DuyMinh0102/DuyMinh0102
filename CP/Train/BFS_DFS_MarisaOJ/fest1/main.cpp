#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, k;
vector<int> g[N], p(N), d(N, -1);
bool check[N] = {false};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= k; ++i) cin >> p[i];

    for (int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        
        g[u].push_back(v); g[v].push_back(u);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[n] = 0;
    pq.push({d[n], n});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if (check[u]) continue;

        check[u] = true;
        for (int v : g[u]){
            if (d[v] > d[u] + 1 || d[v] == -1){
                d[v] = d[u] + 1;
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= k; ++i) cout << d[p[i]] << ' ';
}