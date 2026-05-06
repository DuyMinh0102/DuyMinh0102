#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2505;
const ll INF = 1e18;
int n, m;
ll dist[N];
struct edge{
    ll u, v, w;
    edge() {}
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};
vector<edge> e;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) dist[i] = INF;
    dist[1] = 0;

    for (int i = 0; i < m; ++i){
        ll u, v, w; cin >> u >> v >> w;
        e.push_back(edge(u, v, -w));
    }

    for (int i = 1; i < n; ++i){
        for (const edge j : e){
            if (dist[j.u] != INF){
                if (dist[j.u] + j.w < dist[j.v]){
                    dist[j.v] = dist[j.u] + j.w;
                }  
            } 
        }
    }

    for (int i = 1; i < n; ++i){
        for (const edge j : e){
            if (dist[j.u] != INF){
                if (dist[j.u] == -INF || dist[j.u] + j.w < dist[j.v]) dist[j.v] = -INF;
            }
        }
    }

    if (dist[n] == -INF) cout << -1;
    else cout << -dist[n];
}