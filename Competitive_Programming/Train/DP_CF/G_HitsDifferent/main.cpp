// Source: https://codeforces.com/contest/1829/problem/G
// Status: Pending
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Variables
int t;
ll dp[1505][1505] = {0LL};
ll ans[1000005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll base = 1;
    for (ll i = 1; i <= 1500; ++i){
        for (int j = i - 1; j > 0; --j){
            dp[j][i - j] = dp[j - 1][i - j] + dp[j][i - j - 1] - dp[j - 1][i - j - 1] + base*base;
            ans[base] = dp[j][i - j];
            ++base;
            if (base > 1000000) break;
        }
        if (base > 1000000) break;
    }

    cin >> t;

    while(t--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}