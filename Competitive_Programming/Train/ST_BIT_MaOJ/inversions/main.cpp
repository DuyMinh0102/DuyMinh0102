#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll bit[N];
int n;
vector<int> a(N);

void update(int id, int val){
    for (; id <= n; id += (id & -id)) bit[id] += val;
}

ll query(int id){
    ll sum = 0;
    for (; id > 0; id -= id & -id) sum += bit[id];
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    ll res = 0;

    for (int i = n; i >= 1; i--){
        res += query(a[i] - 1);

        update(a[i], 1);
    }

    cout << res;

    return 0;
}