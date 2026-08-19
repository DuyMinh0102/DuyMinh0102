// Source: https://codeforces.com/problemset/problem/1198/B
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 18/08/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Variables
struct Event {};
struct SegmentTree {
  int N;
  vector<int> t, lazy;

  SegmentTree(int _n) : N(_n), t(4 * _n + 5), lazy(4 * _n + 5, 0) {}

  void build(int k, int l, int r, const vector<int> &a) {
    if (l == r) {
      t[k] = a[l];
      return;
    }

    int mid = l + ((r - l) >> 1);
    build(k << 1, l, mid, a);
    build(k << 1 | 1, mid + 1, r, a);
    t[k] = min(t[k << 1], t[k << 1 | 1]);
  }

  void push(int k) {
    if (lazy[k] == 0)
      return;

    t[k << 1] = max(t[k << 1], lazy[k]);
    lazy[k << 1] = max(lazy[k << 1], lazy[k]);

    t[k << 1 | 1] = max(t[k << 1 | 1], lazy[k]);
    lazy[k << 1 | 1] = max(lazy[k << 1 | 1], lazy[k]);

    lazy[k] = 0;
  }

  void point_upd(int k, int l, int r, int pos, int val) {
    if (l == r) {
      t[k] = val;
      return;
    }

    push(k);
    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
      point_upd(k << 1, l, mid, pos, val);
    else
      point_upd(k << 1 | 1, mid + 1, r, pos, val);

    t[k] = min(t[k << 1], t[k << 1 | 1]);
  }

  int get(int k, int l, int r, int pos) {
    if (l == r) {
      return t[k];
    }

    push(k);
    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
      return get(k << 1, l, mid, pos);

    return get(k << 1 | 1, mid + 1, r, pos);
  }
};
vector<int> a;
int n, q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  a.resize(n + 5);
  SegmentTree st(n);

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  st.build(1, 1, n, a);

  cin >> q;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int p, x;
      cin >> p >> x;

      st.point_upd(1, 1, n, p, x);
    } else {
      int x;
      cin >> x;

      st.lazy[1] = max(st.lazy[1], x);
      st.t[1] = max(st.t[1], x);
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << st.get(1, 1, n, i) << ' ';
}
