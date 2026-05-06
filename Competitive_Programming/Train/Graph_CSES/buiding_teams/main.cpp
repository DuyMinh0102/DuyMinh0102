#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
vector<int> g[N];
int c[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0, u, v; i < m; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int i = 1; i <= n; ++i){
        if (!c[i]){
            queue<int> q;
            q.push(i);
            c[i] = 1;
            
            while (!q.empty()){
                int u = q.front();
                q.pop();
                
                for (int v : g[u]){
                    if (!c[v]) {
                        c[v] = 3 - c[u];
                        q.push(v);
                    } else if (c[v] == c[u]){
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) cout << c[i] << ' ';

    return 0;
}