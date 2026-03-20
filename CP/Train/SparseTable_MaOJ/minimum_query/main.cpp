#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, lg = 19;
int n, q, st[lg][N] = {{0}}, a[N];

int get_id(int id_1, int id_2){
    if (a[id_1] < a[id_2]) return id_1;
    if (a[id_2] < a[id_1]) return id_2;
    return min(id_1, id_2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        st[0][i] = i;
    }

    for (int j = 1; j < lg; ++j){
        for (int i = 1; i + (1 << j) - 1 <= n; ++i){
            st[j][i] = get_id(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }

    while(q--){
        int l, r; cin >> l >> r;
        int k = 31 - __builtin_clz(r - l + 1);

        cout << (get_id(st[k][l], st[k][r - (1 << k) + 1])) << '\n';
    }
}