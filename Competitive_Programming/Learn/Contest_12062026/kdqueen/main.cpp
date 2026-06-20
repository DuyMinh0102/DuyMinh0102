// Source:
// Status:
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 12/06/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const ll MOD = 1e9 + 7;
const int N = 100005;

// Variables
int k;
vector<ll> n(N, 0), x(N, 0), m(N, 0), p2(N, 0);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("kdqueen.inp", "r", stdin);
    freopen("kdqueen.out", "w", stdout);

    cin >> k;
    for (int i = 1; i <= k; ++i) cin >> n[i];

    for (int i = 1; i <= k; ++i) cin >> x[i];

    ll ans = 0;
    for (int i = 1; i <= k; ++i) ans = (ans + n[i] - 1) % MOD;

    ll minm = 2e18;
    for (int i = 1; i <= k; ++i){
      ll L = x[i] - 1, R = n[i] - x[i];

      m[i] = min(L, R);

      minm = min(minm, max(L, R));
    }

    sort(m.begin() + 1, m.begin() + k + 1);
    p2[0] = 1;
    for (int i = 1; i <= k; ++i) p2[i] = (p2[i - 1] * 2) % MOD;

    ll prev = 0;
    for (int j = 1; j <= k; ++j){
      ll cur = min(m[j], minm), len = cur - prev;

      if (len > 0){
        ll cnt = (len % MOD) * p2[k - j + 1] % MOD;

        ans = (ans + cnt) % MOD;
      }
      prev = cur;
    }
    
    ll len = minm - prev;
    if (len > 0){
      ll cnt = (len % MOD) * 1 % MOD;
      ans = (ans + cnt) % MOD;
    }

    cout << ans;
}
