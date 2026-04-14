#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n;
ll k;
ll a[100005];

void solve(){
    cin >> n >> k;
    ll total = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }

    sort(a, a + n);

    int outer = n - 1;
    ll hidden_sum = 0;

    for (int inner = n - 1; inner >= 0; inner--){
        if (inner == outer){
            continue;
        }
        if (a[inner] + k <= a[outer]){
            hidden_sum += a[inner];
            outer--;
        }
    }

    cout << total - hidden_sum;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    freopen("STORAGE.INP", "r", stdin);
    freopen("STORAGE.OUT", "w", stdout);
    solve();
    return 0;
}