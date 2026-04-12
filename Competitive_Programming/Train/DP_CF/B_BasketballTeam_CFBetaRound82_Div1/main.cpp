#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, m, h;
ll s[1005];
ll s_total = 0;
ll s_h, K, N, M;
double prob_no_h = 1.0;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m >> h;

    for (int i = 0; i < m; ++i){
        cin >> s[i];
        s_total += s[i];
    }

    if (s_total < n){
        cout << -1 << "\n";
        return 0;
    }

    s_h = s[h - 1];
    K = n - 1;
    N = s_total - 1;
    M = s_total - s_h;

    if (M < K){
        cout << fixed << setprecision(6) << 1.0 << "\n";
        return 0;
    }

    for (int i = 0; i < K; ++i) prob_no_h *= 1.0 * (M - i) / (N - i);

    cout << fixed << setprecision(6) << 1.0 - prob_no_h << "\n";

    return 0;
}