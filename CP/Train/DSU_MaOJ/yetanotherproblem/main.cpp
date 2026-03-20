#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1e5 + 5;
int n, q, par[N], sz[N], max_sz = 0;
struct value{
    int val, id;
    value(int _val, int _id) : val(_val), id(_id) {}
    bool operator < (const value& other){
        return val < other.val;
    }
};
vector<value> a;

struct query{
    int k, id;
    query(int _k, int _id) : k(_k), id(_id) {}
    bool operator<(const query& other){
        return k < other.k;
    }
};
vector<query> Q;

vector<bool> act;
vector<int> res;

int root(int u){
    return (u == par[u]) ? u : root(par[u]);
}

void uni(int u, int v){
    u = root(u); v = root(v);

    if (u == v) return;

    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    max_sz = max(max_sz, sz[u]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    act.resize(n, false);
    res.resize(q);

    for (int i = 0; i < n; ++i){
        int x; cin >> x;

        a.push_back(value(x, i));

        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < q; ++i){
        int k; cin >> k;

        Q.push_back(query(k, i));
    }

    sort(a.begin(), a.end());
    sort(Q.begin(), Q.end());

    int it = 0, mx = 0;
    int ans[q] = {0};

    for (int i = 0; i < q; ++i){
        while(it < n && a[it].val <= Q[i].k){
            int pos = a[it].id;
            act[pos] = true;     

            mx = max(mx, 1);
            max_sz = max(max_sz, mx);

            if (pos > 0 && act[pos - 1]) uni(pos, pos - 1);

            if (pos < n - 1 && act[pos + 1]) uni(pos, pos + 1);

            mx = max(mx, max_sz);
            ++it;
        }
        ans[Q[i].id] = mx;
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}