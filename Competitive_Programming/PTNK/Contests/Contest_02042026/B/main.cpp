// Source: ..
// Status: Solved
/*
Note: idk I lost the original problem

Solution: Seems like some kind of distance calculating

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 02/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<vector<int>> g;
vector<int> p_node;
vector<bool> vis;
int c_start = -1, c_end = -1;

bool dfs_cycle(int u, int p) {
    vis[u] = true;
    for (int v : g[u]) {
        if (v == p) continue;
        if (vis[v]) {
            c_start = v;
            c_end = u;
            return true;
        }
        p_node[v] = u;
        if (dfs_cycle(v, u)) return true;
    }
    return false;
}

int bfs(int start, int ig_u, int ig_v, int& mx_d) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest = start;
    mx_d = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if ((u == ig_u && v == ig_v) || (u == ig_v && v == ig_u)) continue;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                if (dist[v] > mx_d) {
                    mx_d = dist[v];
                    farthest = v;
                }
                q.push(v);
            }
        }
    }
    return farthest;
}

int get_dia(int ig_u, int ig_v) {
    int mx_d = 0;
    int a = bfs(1, ig_u, ig_v, mx_d);
    bfs(a, ig_u, ig_v, mx_d);
    return mx_d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    g.resize(n + 1);
    p_node.resize(n + 1, -1);
    vis.resize(n + 1, false);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_cycle(1, 0);

    vector<pair<int, int>> cycle;
    cycle.push_back({c_start, c_end});
    int curr = c_end;
    while (curr != c_start) {
        cycle.push_back({curr, p_node[curr]});
        curr = p_node[curr];
    }

    int ans = 0;
    for (auto edge : cycle) {
        ans = max(ans, get_dia(edge.first, edge.second));
    }

    cout << ans << "\n";

    return 0;
}