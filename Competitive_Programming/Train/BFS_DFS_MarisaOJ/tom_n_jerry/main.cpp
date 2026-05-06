#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, a, b;
vector<int> g[N], d_a(N, -1), d_b(N, -1);

void path(int s, vector<int>& d){
    queue<int> q;

    q.push(s);
    d[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (int v : g[u]){
            if (d[v] > d[u] + 1 || d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m >> a >> b;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v); g[v].push_back(u);
    }

    path(a, d_a);
    path(b, d_b);

    int res = 0;

    for (int i = 1; i <= n; ++i){
        res += (d_a[i] <= d_b[i]);
    }

    cout << res;
}