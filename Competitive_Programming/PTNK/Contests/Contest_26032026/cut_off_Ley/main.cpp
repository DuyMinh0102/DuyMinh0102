#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
struct E {
    int v;
    ll c, f;
    int r;
};

int n, m, s, t;
vector<vector<E>> g;
vector<int> d;
vector<int> p;

void add(int u, int v, ll c) {
    g[u].push_back({v, c, 0, (int)g[v].size()});
    g[v].push_back({u, c, 0, (int)g[u].size() - 1});
}

bool bfs() {
    fill(d.begin(), d.end(), -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& e : g[u]) {
            if (e.c - e.f > 0 && d[e.v] == -1) {
                d[e.v] = d[u] + 1;
                q.push(e.v);
            }
        }
    }
    return d[t] != -1;
}

ll dfs(int u, ll push) {
    if (push == 0) return 0;
    if (u == t) return push;

    for (int& i = p[u]; i < g[u].size(); ++i) {
        auto& e = g[u][i];
        int v = e.v;

        if (d[u] + 1 != d[v] || e.c - e.f == 0) continue;

        ll pushed = dfs(v, min(push, e.c - e.f));

        if (pushed == 0) continue;

        e.f += pushed;
        g[v][e.r].f -= pushed;
        return pushed;
    }
    return 0;
}

ll dinic() {
    ll flow = 0;
    while (bfs()) {
        fill(p.begin(), p.end(), 0);
        while (ll pushed = dfs(s, inf)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    g.assign(n + 1, vector<E>());
    d.resize(n + 1);
    p.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v; ll c; cin >> u >> v >> c;

        add(u, v, c);
    }

    cin >> s >> t;

    cout << dinic() << "\n";

    return 0;
}