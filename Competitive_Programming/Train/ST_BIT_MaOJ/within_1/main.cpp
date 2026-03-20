#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int st[4*N] = {0}, lazy[4*N] = {0}, n, LIM = 1e9;
struct lines{
    int l, r;
} line[N];

void push(int k){
    if (lazy[k] == 0) return;
    --lazy[k];

    lazy[k * 2]++;
    st[k * 2]++;

    lazy[k * 2 + 1]++;
    st[k * 2 + 1]++;
}

void upd(int k, int l, int r, int u, int v){
    if (r < u || l > v) return;
    if (u <= l && r <= v){
        ++st[k];
        ++lazy[k];
        return;
    }

    push(k);
    int mid = l + (r - l) / 2;
    upd(k * 2, l, mid, u, v);
    upd(k * 2 + 1, mid + 1, r, u, v);
    st[k] = min(st[k * 2], st[k * 2 + 1]);
}

int query(int k, int l, int r, int u, int v){
    if (r < u || l > v) return LIM;
    if (u <= l && r <= v) return st[k];

    push(k);

    int mid = l + (r - l) / 2;
    return min(query(k * 2, l, mid, u, v), query(k * 2 + 1, mid + 1, r, u, v));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i){
        cin >> line[i].l >> line[i].r;
        upd(1, 1, n, line[i].l + 1, max(1, line[i].r - 1));
    }

    for (int i = 1; i <= n; ++i){
        cout << query(1, 1, n, line[i].l, line[i].r) - 1 << '\n';;
    }
}