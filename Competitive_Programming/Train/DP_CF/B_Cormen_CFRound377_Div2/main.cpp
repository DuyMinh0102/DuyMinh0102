#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, k, a[N];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int cnt = 0;

    for (int i = 1; i < n; ++i){
        int pre = a[i] + a[i - 1], org = a[i];
        if (pre < k) a[i] = k - a[i - 1];

        cnt += abs(a[i] - org);
    }

    cout << cnt << '\n';
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
}