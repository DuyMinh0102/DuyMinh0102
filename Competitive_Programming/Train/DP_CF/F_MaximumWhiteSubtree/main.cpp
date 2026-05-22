// Source: https://codeforces.com/contest/1324/problem/f
// Status: Solved
/*
Note: for each vertex v in the query, look for a subtree that contains vertex v
and has the maximum difference of black and white nodes.

Solution: We calculate the contribution for each vetices: (white: +1, black: -1)
For each node u, calcualte the contribution from it's child
Then, for each node u, calculate the contribution it can get from it's parents

Author: Nguyen Duy Minh - studying at High school for the gifted, VNU - HCM.
Date: 20/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// DEBUG
#define dbg(testingline, debugdescription, testedvariable)                     \
    cerr << "debug on line " << testingline << ': ' << debugdescription << ' ' \
         << testedvariable << '\n';

// CONFIG
#define pb push_back
#define ll long long
const int N = 200005;

// VARIABLES
int n;
vector<int> g[N], dp(N, 0), ans(N, 0), w(N, 0);

void dfs1(int u, int p) {
    dp[u] = w[u];

    for (int v : g[u]) {
        if (v == p) continue;

        dfs1(v, u);

        dp[u] += max(0, dp[v]);
    }
}

void dfs2(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;

        ans[v] = dp[v] + max(0, ans[u] - max(0, dp[v]));

        dfs2(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        if (w[i] == 0) --w[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs1(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
