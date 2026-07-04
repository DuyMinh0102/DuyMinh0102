#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N];

struct Node {
    int cnt[3], lazy;
} t[4 * N];

void pull(int k){
    for (int i = 0; i < 3; i++) t[k].cnt[i] = t[k << 1].cnt[i] + t[k << 1 | 1].cnt[i];
}

void apply_shift(int k, int v){
    v %= 3;
    if (v == 0) return;
    if (v == 1){
        int tmp = t[k].cnt[2];
        t[k].cnt[2] = t[k].cnt[1];
        t[k].cnt[1] = t[k].cnt[0];
        t[k].cnt[0] = tmp;
    } else{
        int tmp = t[k].cnt[0];
        t[k].cnt[0] = t[k].cnt[1];
        t[k].cnt[1] = t[k].cnt[2];
        t[k].cnt[2] = tmp;
    }
    t[k].lazy = (t[k].lazy + v) % 3;
}

void push(int k){
    if (t[k].lazy != 0){
        apply_shift(k << 1, t[k].lazy);
        apply_shift(k << 1 | 1, t[k].lazy);
        t[k].lazy = 0;
    }
}

void build(int k, int l, int r){
    t[k].lazy = 0;
    if (l == r){
        int rem = a[l] % 3;
        t[k].cnt[0] = t[k].cnt[1] = t[k].cnt[2] = 0;
        t[k].cnt[rem] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    pull(k);
}

void update(int k, int l, int r, int u, int v) {
    if (u <= l && r <= v){
        apply_shift(k, 1);
        return;
    }
    push(k);
    int mid = (l + r) >> 1;
    if (u <= mid) update(k << 1, l, mid, u, v);
    if (v > mid) update(k << 1 | 1, mid + 1, r, u, v);
    pull(k);
}

int query(int k, int l, int r, int u, int v){
    if (u <= l && r <= v) return t[k].cnt[0];
    push(k);
    int mid = (l + r) >> 1;
    int res = 0;
    if (u <= mid) res += query(k << 1, l, mid, u, v);
    if (v > mid) res += query(k << 1 | 1, mid + 1, r, u, v);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    while (q--){
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) update(1, 1, n, l, r);
        else cout << query(1, 1, n, l, r) << "\n";
    }
    return 0;
}