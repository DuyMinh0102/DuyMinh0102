#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, par[N], p[N];

int findpar(int u){
    if (u == par[u]) return u;
    return par[u] = findpar(par[u]);
}

void uni(int u, int v){
    u = findpar(u);
    v = findpar(v);

    par[u] = v;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> p[i];
        par[i] = i;
        --p[i];
    }

    for (int i = 0; i < n; ++i){
        int u = findpar(p[i]);
        cout << u + 1 << ' ';
        uni(u, (u + 1) % n);
    }
}