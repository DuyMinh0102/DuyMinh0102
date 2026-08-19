// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
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
const int N = 100005;

// Variables
int n, m;
vector<pair<int, int>> h(N);
struct node {
  int pref, suf, lc, rc, mx, len;

  node() : pref(0), suf(0), lc(0), rc(0), mx(0), len(0) {};

  node(int _pref, int _lc, int _rc, int _mx, int _len)
      : pref(_pref), lc(_lc), rc(_rc), mx(_mx), len(_len) {}
} t[20 * N];
int root[N], nodecnt = 0;

void merge(int id, int l, int r) {
  int mid = l + ((r - l) >> 1);
  int lenl = mid - l + 1, lenr = r - mid;

  node &curr = t[id];
  node &left = t[curr.lc], &right = t[curr.rc];

  curr.len = left.len + right.len;
  curr.mx = max({left.mx, right.mx, left.suf + right.pref});
  curr.pref = left.pref == lenl ? lenl + right.pref : left.pref;
  curr.suf = right.suf == lenr ? left.suf + lenr : right.suf;
}

node combine(node L, node R) {
  if (L.len == 0)
    return R;
  if (R.len == 0)
    return L;

  node res;
  res.len = L.len + R.len;
  res.mx = max({L.mx, R.mx, L.suf + R.pref});
  res.pref = L.pref == L.len ? L.len + R.pref : L.pref;
  res.suf = R.suf == R.len ? L.suf + R.len : R.suf;

  return res;
}

int upd(int prev, int l, int r, int pos) {
  int curr = ++nodecnt;
  t[curr] = t[prev];

  if (l == r) {
    t[curr].mx = t[curr].pref = t[curr].suf = t[curr].len = 1;
    return curr;
  }

  int mid = l + ((r - l) >> 1);
  if (pos <= mid)
    t[curr].lc = upd(t[curr].lc, l, mid, pos);
  else
    t[curr].rc = upd(t[curr].rc, mid + 1, r, pos);

  merge(curr, l, r);

  return curr;
}

node query(int id, int l, int r, int liml, int limr) {
  if (l > limr || r < liml)
    return node();

  if (liml <= l && r <= limr) {
    node res = t[id];
    res.len = r - l + 1;
    return res;
  }

  int mid = l + ((r - l) >> 1);
  if (limr <= mid)
    return query(t[id].lc, l, mid, liml, limr);
  if (liml > mid)
    return query(t[id].rc, mid + 1, r, liml, limr);

  return combine(query(t[id].lc, l, mid, liml, limr),
                 query(t[id].rc, mid + 1, r, liml, limr));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i].first;
    h[i].second = i;
  }
  sort(h.begin() + 1, h.begin() + n + 1, greater<pair<int, int>>());
  root[0] = 0;
  for (int i = 1; i <= n; ++i) {
    root[i] = upd(root[i - 1], 1, n, h[i].second);
  }

  cin >> m;
  while (m--) {
    int l, r, w;
    cin >> l >> r >> w;

    int lo = 1, hi = n, id = n;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);

      if (query(root[mid], 1, n, l, r).mx >= w) {
        id = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }

    cout << h[id].first << '\n';
  }
}
