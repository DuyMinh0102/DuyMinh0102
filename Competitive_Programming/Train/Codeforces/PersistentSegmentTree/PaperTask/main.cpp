// Source: https://codeforces.com/contest/653/problem/F
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 22/07/2026 (DD/MM/YYYY).
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
const int N = 500005;

// Variables
struct node {
  int lc, rc, sum;
} t[N * 25];

int root[N], nodecnt = 0;

int upd(int prev, int l, int r, int val) {
  int cur = ++nodecnt;
  t[cur] = t[prev];
  ++t[cur].sum;

  if (l == r)
    return cur;

  int mid = l + ((r - l) >> 1);
  if (val <= mid)
    t[cur].lc = upd(t[cur].lc, l, mid, val);
  else
    t[cur].rc = upd(t[cur].rc, mid + 1, r, val);

  t[cur].sum = t[t[cur].lc].sum + t[t[cur].rc].sum;
  return cur;
}

int query(int node, int l, int r, int val) {
  if (!node)
    return 0;
  if (l == r)
    return t[node].sum;

  int mid = l + ((r - l) >> 1);
  if (val <= mid)
    return query(t[node].lc, l, mid, val);

  return query(t[node].rc, mid + 1, r, val);
}

int query_freq(int a, int b, int val, int mxval) {
  if (a > b)
    return 0;

  int cntb = query(root[b], 0, mxval, val);
  int cnta = (a > 0) ? query(root[a - 1], 0, mxval, val) : 0;

  return cntb - cnta;
}

struct state {
  int len, link, pos;

  map<char, int> nxt;
} st[N * 2];

int sz = 1, lst = 1;

void sam(char c, int id) {
  int cur = ++sz;
  st[cur].len = st[lst].len + 1;
  st[cur].pos = id;
  int p = lst;

  while (p && !st[p].nxt.count(c)) {
    st[p].nxt[c] = cur;
    p = st[p].link;
  }

  if (!p)
    st[cur].link = 1;

  else {
    int q = st[p].nxt[c];

    if (st[p].len + 1 == st[q].len)
      st[cur].link = q;
    else {
      int clone = ++sz;
      st[clone].len = st[p].len + 1;
      st[clone].nxt = st[q].nxt;
      st[clone].link = st[q].link;
      st[clone].pos = st[q].pos;

      while (p && st[p].nxt[c] == q) {
        st[p].nxt[c] = clone;
        p = st[p].link;
      }

      st[q].link = st[cur].link = clone;
    }
  }
  lst = cur;
}

int n, P[N], kmin[N];
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;

  int offset = n, mxval = 2 * n;

  P[0] = 0;

  for (int i = 1; i <= n; ++i) {
    P[i] = P[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    sam(s[i - 1], i);
  }

  root[0] = upd(0, 0, mxval, P[0] + offset);

  for (int i = 1; i <= n; ++i)
    root[i] = upd(root[i - 1], 0, mxval, P[i] + offset);

  vector<int> stack;
  for (int r = 1; r <= n; ++r) {
    while (!stack.empty() && P[stack.back()] >= P[r])
      stack.pop_back();

    kmin[r] = stack.empty() ? 0 : stack.back() + 1;
    stack.pb(r);
  }

  ll ans = 0;
  for (int u = 2; u <= sz; ++u) {
    int r = st[u].pos, a = max(r - st[u].len, kmin[r]),
        b = r - st[st[u].link].len - 1;

    if (a <= b)
      ans += query_freq(a, b, P[r] + offset, mxval);
  }

  cout << ans;
}
