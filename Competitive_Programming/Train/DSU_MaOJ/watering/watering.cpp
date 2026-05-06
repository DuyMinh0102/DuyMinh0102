#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, a[N], b[N][N], par[N];
struct edge{
    int u, v, w;
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
    bool operator<(const edge& other){
        return w < other.w;
    }
};
vector<edge> e;

int findpar(int u){
    return (par[u] == u) ? u : par[u] = findpar(par[u]);
}

bool uni(int u, int v){
    u = findpar(u); v = findpar(v);

    if (u == v) return false;
    par[v] = u;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i){
        par[i] = i;
        int x; cin >> x;
        e.push_back(edge(0, i, x));
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            e.push_back(edge(i, j, x));
        }
    }

    sort(e.begin(), e.end());


    int sum = 0;
    for (edge ed : e){
        if (uni(ed.u, ed.v)) sum += ed.w;
    }

    cout << sum;
}