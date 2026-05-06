// Source: https://codeforces.com/contest/706/problem/C
// Status: Solved
/*
Note: N strings, you can reverse any string, each reverse will cost C_i energy (i is the index of the reversed string).
Determine if you can make the N strings lexicographically ordered, else output -1.

Solution: let dp[i][j] be the min cost if the current string is in the j state. (where j = [0; 1]. 1 is reversed, 0 is not)
we then check four possible combinations for the i-th string.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 24/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long
const int N = 1e5 + 5;
const ll INF = 1e18;

// Variables
int n, c[N];
ll dp[N][2];
vector<string> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n + 1);
    
    for (int i = 1; i <= n; ++i){
        dp[i][0] = dp[i][1] = INF;
    }

    for (int i = 1; i <= n; ++i) cin >> c[i];

    for (int i = 1; i <= n; ++i) cin >> a[i];

    dp[1][0] = 0;
    dp[1][1] = c[1];

    string pre_rev = a[1];
    reverse(pre_rev.begin(), pre_rev.end());
    for (int i = 2; i <= n; ++i){
        string rev_i = a[i];
        reverse(rev_i.begin(), rev_i.end());

        if (a[i] >= a[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (a[i] >= pre_rev) dp[i][0] = min(dp[i][0], dp[i - 1][1]);

        if (rev_i >= a[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);
        if (rev_i >= pre_rev) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);

        pre_rev = rev_i;
    }

    ll res = min(dp[n][0], dp[n][1]);

    if (res >= INF) cout << -1;
    else cout << res;
}