#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int n, q;
int vals[N * N];

struct Element {
    int val;
    short r, c; 
    bool operator<(const Element& o) const {
        return val < o.val;
    }
} elements[N * N];

struct Node {
    short min_col, max_col, min_row, max_row;
} t[4 * N * N];

void build(int k, int l, int r) {
    if (l == r) {
        t[k].min_row = elements[l].r;
        t[k].max_row = elements[l].r;
        t[k].min_col = elements[l].c;
        t[k].max_col = elements[l].c;
        return;
    }

    int mid = l + (r - l) / 2;
    int lc = k * 2, rc = k * 2 + 1;
    
    build(lc, l, mid);
    build(rc, mid + 1, r);

    t[k].min_row = min(t[lc].min_row, t[rc].min_row);
    t[k].max_row = max(t[lc].max_row, t[rc].max_row);
    t[k].min_col = min(t[lc].min_col, t[rc].min_col);
    t[k].max_col = max(t[lc].max_col, t[rc].max_col);
}

int qr1, qc1, qr2, qc2;

int get(int k, int l, int r, int& K) {
    if (t[k].max_row < qr1 || t[k].min_row > qr2 || t[k].max_col < qc1 || t[k].min_col > qc2) {
        return -1;
    }
    
    if (t[k].min_row >= qr1 && t[k].max_row <= qr2 && t[k].min_col >= qc1 && t[k].max_col <= qc2) {
        int cnt = r - l + 1;
        if (K > cnt) {
            K -= cnt;
            return -1;
        }
    }
    
    if (l == r) {
        if (K == 1) return l; 
        K--; 
        return -1;
    }

    int mid = l + (r - l) / 2;
    
    int res = get(k * 2, l, mid, K);
    if (res != -1) return res;
    
    return get(k * 2 + 1, mid + 1, r, K);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!(cin >> n >> q)) return 0;

    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> elements[idx].val;
            elements[idx].r = i;
            elements[idx].c = j;
            idx++;
        }
    }

    sort(elements, elements + (n * n));

    for (int i = 0; i < n * n; ++i) {
        vals[i] = elements[i].val;
    }

    build(1, 0, n * n - 1);

    while (q--) {
        int k;
        cin >> qr1 >> qc1 >> qr2 >> qc2 >> k;
        
        int ans = get(1, 0, n * n - 1, k);
        
        if (ans != -1) {
            cout << vals[ans] << "\n";
        }
    }

    return 0;
}