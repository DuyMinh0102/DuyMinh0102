// Source: https://codeforces.com/contest/161/problem/D
// Status: Solved
/*
Note: Count the number of pairs (u, v) such that the distance from u to v is k.

Solution: let dp[u][i] be the amount of nodes is i nodes away from u.


Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 19/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long
const int N = 5e4 + 5;

// Variables
int n, k;
vector<int> g[N];
ll dp[N][505], sum = 0;

void dfs(int u, int p){
    dp[u][0] = 1;
    for (int v : g[u]){
        if (v != p){
            dfs(v, u);

            for (int i = 1; i <= k; ++i) sum += dp[u][k - i] * dp[v][i - 1];

            for (int i = 1; i <= k; ++i) dp[u][i] += dp[v][i - 1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1, 0);

    cout << sum;
}