#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("bonus.inp", "r", stdin); freopen("bonus.out", "w", stdout);

    cin >> n;

    vector<ll> p = {2, 3, 5, 7};

    ll t = n + (n / (2 * 3 * 5 * 7));

    for (int i = 0; i < 4; ++i){
        t -= (n / p[i]);
        for (int j = i + 1; j < 4; ++j){
            t += (n / (p[i] * p[j]));
            for (int k = j + 1; k < 4; ++k){
                t -= (n / (p[i]*p[j]*p[k]));
            }
        }   
    }

    cout << t;
}