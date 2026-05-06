// Source: https://codeforces.com/contest/1528/problem/A
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 24/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 1e5 + 5;

// Variables
int t, n;
vector<int> g[N];
ll L[N], R[N], dp[N][2];

void dfs(int u, int p){
    dp[u][0] = 0;
    dp[u][1] = 0;

    for (int v : g[u]){
        if (v == p) continue;

        dfs(v, u);

        dp[u][0] += max(dp[v][0] + abs(L[u] - L[v]), dp[v][1] + abs(L[u] - R[v]));
        dp[u][1] += max(dp[v][0] + abs(R[u] - L[v]), dp[v][1] + abs(R[u] - R[v]));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--){
        cin >> n;

        for (int i = 1; i <= n; ++i){
            cin >> L[i] >> R[i];
            g[i].clear();
        }
        
        for (int i = 1; i < n; ++i){
            int u, v; cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }

        dfs(1, 0);

        cout << max(dp[1][0], dp[1][1]) << '\n';
    }
}