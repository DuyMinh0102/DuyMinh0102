#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pl pair<ll, ll>
const int N = 505;
int n, m, k;
vector<int> post;
vector<vector<ll>> g(N, vector<ll>(N    , 1e18));

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);

    for (int i = 0; i < k; ++i){
        int x; cin >> x;
        post.push_back(x);
    }

    for (int i = 0; i < m; ++i){
        int u, v, w; cin >> u >> v >> w;

        g[u][u] = g[v][v] = 0;

        g[u][v] = g[v][u] = w;
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            for (int k = 1; k <= n; ++k){
                if (i != j && i != k && j != k){
                    
                }
            }   
        }
    }
}