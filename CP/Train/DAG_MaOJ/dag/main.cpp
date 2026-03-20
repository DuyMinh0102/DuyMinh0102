#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<int> g[N];
int check[N] = {0};

bool dfs(int u, int p){
    check[u] = 1;

    for (int v : g[u]){
        if (check[v] == 1) return false;
        if (check[v] == 0) if (!dfs(v, u)) return false;
    }

    check[u] = 2;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;

        g[u].push_back(v);
    }

    check[0] = true;

    for (int i = 1; i <= n; ++i){
        if (check[i] == 0){
            if (!dfs(i, 0)){
                cout << "NO"; return 0;
            }
        }
    }

    cout << "YES";
}