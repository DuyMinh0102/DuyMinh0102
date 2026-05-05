#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, LIM = 1e9;
int n, k;
ll a[N];

bool check(double m){
    vector<double> f(n + 1, 0.0);

    for (int i = 1  ; i <= n; ++i) f[i] = f[i - 1] + a[i] - m;
    
    double mn = LIM;

    for (int i = k + 1; i <= n; ++i){
        mn = min(mn, f[i - k]);

        if (f[i] - mn >= 0) return true;
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    double l = 1, r = LIM, e = 1e-7, res;

    while(r - l >= e){
        double mid = l + (r - l)/2.0;

        if (check(mid)){
            res = mid;
            l = mid;
        }
        else r = mid;
    }

    cout << fixed << setprecision(3) << res;
}