#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, q, b_sz, cnt[N], a[N], compressed[N], res = 0, ans[N];

struct query{
    int l, r, id;
    bool operator < (query& other){
        int b_a = l / b_sz, b_b = other.l / b_sz;
        if (b_a != b_b) return b_a < b_b;

        return (b_a & 1) ? r < other.r : r > other.r;
    }
} Q[N];

void add(int id){
    int u = compressed[a[id]];
    ++cnt[u];
    if (cnt[u] == 3) --res;
    else if (cnt[u] == 2) ++res;
}

void del(int id){
    int u = compressed[a[id]];
    --cnt[u];
    if (cnt[u] == 1) --res;
    if (cnt[u] == 2) ++res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("dtwice.inp", "r", stdin); freopen("dtwice.out", "w", stdout);

    cin >> n >> q;

    b_sz = sqrt(n);

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        compressed[i] = a[i];
    }

    sort(compressed + 1, compressed + n + 1);
    int m = unique(compressed + 1, compressed + n + 1) - compressed;
    for (int i = 1; i <= n; ++i){
        a[i] = lower_bound(compressed + 1, compressed + n + 1, a[i]) - compressed;
    }

    for (int i = 0; i < q; ++i){
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }

    sort(Q, Q + q);

    int l = 1, r = 0;
    for (int i = 0; i < q; ++i){
        while(l < Q[i].l) del(l++);
        while(l > Q[i].l) add(--l);

        while(r < Q[i].r) add(++r);
        while(r > Q[i].r) del(r--);

        ans[Q[i].id] = res;
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}