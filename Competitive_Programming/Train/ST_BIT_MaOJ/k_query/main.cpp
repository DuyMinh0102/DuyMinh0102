#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, bit[N], ans[N], sz;
struct query{
    int l, r, k, id;
    bool operator<(const query& other){
        return k > other.k;
    }
} Q[N];

struct element{
    int val, pos;
    bool operator<(const element& other){ return val > other.val;}
} a[N];

void update(int id, int val){
    for (; id <= n; id += id & -id) bit[id] += val;
}

int cnt(int id){
    int s = 0;
    for (; id > 0; id -= id & -id) s += bit[id];
    return s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i){
        cin >> a[i].val;
        a[i].pos = i;
    }
    
    for (int i = 0; i < q; ++i){
        cin >> Q[i].l >> Q[i].r >> Q[i].k;
        Q[i].id = i;
    }

    sort(a + 1, a + n + 1);
    sort(Q, Q + q);

    int cur = 1;
    for (int i = 0; i < q; ++i){
        while(cur <= n && a[cur].val > Q[i].k){
            update(a[cur].pos, 1);
            ++cur;
        }

        ans[Q[i].id] = cnt(Q[i].r) - cnt(Q[i].l - 1);
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}