// Source: Problems/unsolved/cgraph.jpg
// Status: 80%
/* 
Note: Given an undirect graph with n vertices and m edges.
Answer Q queries. Each query is a pair of intergers L and R.
For each query, count the number of connected components in the graph formed by edges with indices
within the range [L, R].

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 23/02/2026
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
int n, m, q, b_sz, cnt;
int par[N], sz[N], ans[N];

struct edge {
    int u, v;
};
vector<edge> e;

struct query {
    int l, r, id;
} Q[N];

struct update {
    int u, v, old_sz_u;
};
stack<update> st;

bool cmp(query a, query b) {
    int ba = a.l / b_sz, bb = b.l / b_sz;
    if (ba != bb) return ba < bb;
    return a.r < b.r;
}

int findpar(int u) {
    while (u != par[u]) u = par[u];
    return u;
}

void uni(int u, int v, bool can_rollback) {
    u = findpar(u); v = findpar(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    if (can_rollback) st.push({u, v, sz[u]});
    par[v] = u;
    sz[u] += sz[v];
    cnt--;
}

void rollback(int target) {
    while (st.size() > target) {
        update t = st.top();
        st.pop();
        sz[t.u] = t.old_sz_u;
        par[t.v] = t.v;
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    freopen("cgraph.inp", "r", stdin);
    freopen("cgraph.out", "w", stdout);

    cin >> n >> m >> q;
    b_sz = max(1.0, m / sqrt(q + 1));

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e.push_back({u, v});
    }

    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].l--; Q[i].r--;
        Q[i].id = i;
    }

    sort(Q, Q + q, cmp);

    int cur_b = -1;
    int L, R;

    for (int i = 0; i < q; i++) {
        int block = Q[i].l / b_sz;

        if (block != cur_b) {
            for (int j = 1; j <= n; j++) {
                par[j] = j;
                sz[j] = 1;
            }
            while (!st.empty()) st.pop();
            cnt = n;
            cur_b = block;
            R = (block + 1) * b_sz - 1;
        }

        if (Q[i].r < (block + 1) * b_sz) {
            int prev_cnt = cnt;
            int snapshot = st.size();
            for (int j = Q[i].l; j <= Q[i].r; j++) uni(e[j].u, e[j].v, true);
            ans[Q[i].id] = cnt;
            rollback(snapshot);
            cnt = prev_cnt;
            continue;
        }

        while (R < Q[i].r) {
            R++;
            uni(e[R].u, e[R].v, false);
        }

        int prev_cnt = cnt;
        int snapshot = st.size();
        for (int j = (block + 1) * b_sz - 1; j >= Q[i].l; j--) {
            uni(e[j].u, e[j].v, true);
        }
        ans[Q[i].id] = cnt;
        rollback(snapshot);
        cnt = prev_cnt;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
    return 0;
}