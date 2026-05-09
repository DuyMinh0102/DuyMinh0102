// Source: https://codeforces.com/contest/2063/problem/C
// Status: Pending
/*
Note: Remove two vertices and the edges connected to those so that the amount of connected components left is maximized

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 09/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Variables
int t, n;

void solve(){
    cin >> n;

    vector<set<int>> g(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 1; i < n; ++i){
        int u, v; cin >> u >> v;
        g[u].insert(v); g[v].insert(u);

        ++deg[u];
        ++deg[v];
    }

    vector<pair<int, int>> sort_deg;
    for (int i = 1; i <= n; ++i){
        sort_deg.pb({deg[i], i});
    }
    sort(sort_deg.rbegin(), sort_deg.rend());

    int mx = 0;

    for (int i = 1; i <= n ; ++i){
        for (int j = 0; j < n; ++j){
            int u = i, v = sort_deg[j].second;

            if (u == v) continue;

            if (g[u].count(v)) mx = max(mx, deg[u] + sort_deg[j].first - 2);
            else{
                mx = max(mx, deg[u] + sort_deg[j].first - 1);
                break;
            }
        }
    }

    cout << mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
}