#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 300005;
struct query{
    int l, r;
    ll a;
    query() {}

    query(int _l, int _r, ll _a): l(_l), r(_r), a(_a) {}
};
int n, m, k;
int p[N];
vector<query> Q;
ll bit[N];
vector<int> L, R, ans, own[N];

void upd(int id, ll val){
    for (; id <= m + 1; id += (id & -id)) bit[id] += val;
}

ll sum(int id){
    ll res = 0;
    for (; id > 0; id -= (id & -id)) res += bit[id];
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for (int i = 1; i <= m; ++i){
        int x; cin >> x;
        own[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> p[i];

    cin >> k;
    for (int i = 0; i < k; ++i){
        int l, r, a; cin >> l >> r >> a;
        Q.push_back(query(l, r, a));
    }

    L.resize(n + 1, 0); R.resize(n + 1, k - 1); ans.resize(n + 1, -1);

    bool c = true;
    while(c){
        c = false;
        vector<int> check[k + 1];
        for (int i = 1; i <= n; ++i){
            if (L[i] <= R[i]){
                int mid = L[i] + (R[i] - L[i] >> 1);
                check[mid].push_back(i);
                c = true;
            }
        }

        if (!c) break;

        for (int i = 1; i <= m + 1; ++i) bit[i] = 0;

        for (int i = 0; i < k; ++i){
            int l = Q[i].l, r = Q[i].r;
            ll a = Q[i].a;
            if (l <= r){
                upd(l, a);
                upd(r + 1, -a);
            }
            else{
                upd(l, a);
                upd(1, a);
                upd(r + 1, -a);
            }

            for (int id : check[i]){
                ll cur = 0;
                for (int land : own[id]){
                    cur += sum(land);
                    if (cur > p[id]) break;
                }
                if (cur >= p[id]){
                    ans[id] = i + 1;
                    R[id] = i - 1;
                }
                else L[id] = i + 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        cout << ans[i] << '\n';
    }
}