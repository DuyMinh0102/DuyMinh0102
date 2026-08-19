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
const int N = 75005;
const int MAX_X = 200005;
const int MOD = 1000000000;

// Variables
int n, m;
struct node {
  int lc, rc;
  ll a, b;
} t[110 * N];
int root[N], nodecnt = 0;
ll pref_y2[N];

int upd(int prev, int l, int r, int liml, int limr, ll A, ll B) {
  if (l > limr || r < liml)
    return prev;

  int curr = ++nodecnt;
  t[curr] = t[prev];

  if (liml <= l && r <= limr) {
    t[curr].a += A;
    t[curr].b += B;
    return curr;
  }

  int mid = l + ((r - l) >> 1);
  t[curr].lc = upd(t[curr].lc, l, mid, liml, limr, A, B);
  t[curr].rc = upd(t[curr].rc, mid + 1, r, liml, limr, A, B);

  return curr;
}

ll query(int curr, int l, int r, ll x) {
  if (!curr)
    return 0;

  ll val = t[curr].a * x + t[curr].b;

  if (l == r)
    return val;

  int mid = l + ((r - l) >> 1);
  if (x <= mid)
    return val + query(t[curr].lc, l, mid, x);

  return val + query(t[curr].rc, mid + 1, r, x);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  root[0] = 0;

  for (int i = 1; i <= n; ++i) {
    ll x1, x2, y1, y2, a, b;

    cin >> x1 >> x2 >> y1 >> a >> b >> y2;

    pref_y2[i] = pref_y2[i - 1] + y2;

    int rt = root[i - 1];

    if (x1 >= 0)
      rt = upd(rt, 0, MAX_X, 0, x1, 0, y1);
    if (x1 + 1 <= x2)
      rt = upd(rt, 0, MAX_X, x1 + 1, x2, a, b);
    if (x2 + 1 <= MAX_X)
      rt = upd(rt, 0, MAX_X, x2 + 1, MAX_X, 0, y2);

    root[i] = rt;
  }

  cin >> m;

  ll last = 0;
  while (m--) {
    int l, r;
    ll x;
    cin >> l >> r >> x;

    x = (x + last) % MOD;
    ll ans = 0;

    if (x > MAX_X)
      ans = pref_y2[r] - pref_y2[l - 1];
    else {
      ll val_r = query(root[r], 0, MAX_X, x);
      ll val_l = query(root[l - 1], 0, MAX_X, x);
      ans = val_r - val_l;
    }

    cout << ans << '\n';
    last = ans;
  }
}
