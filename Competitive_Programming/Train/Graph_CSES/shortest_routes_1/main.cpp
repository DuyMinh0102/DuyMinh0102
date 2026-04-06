#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll, ll>
const int N = 1e5 + 5;
int n, m;
ll d[N];
vector<pl> g[N];    

void djikstra(){
    priority_queue<pl, vector<pl>, greater<pl>> pq;
    d[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int u = pq.top().second, dist = pq.top().first;
        pq.pop();

        if (dist > d[u]) continue;

        for (auto [v, w] : g[u]){
            if (d[v] <= d[u] + w && d[v] != -1) continue;

            d[v] = d[u] + w;
            pq.push({d[v], v});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    memset(d, -1, sizeof(d));

    for (int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    djikstra();
    for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
}
