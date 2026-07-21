// Source: https://codeforces.com/problemset/problem/762/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 20/07/2026 (DD/MM/YYYY).
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
const ll minx = -1000000000LL;
const ll maxx = 2000000000LL;
const int maxf = 10000;

// Variables
struct station {
  ll x, r;
  int f;

  bool operator<(const station &other) { return r > other.r; }
};
struct Node {
  int sum, le, ri;
} t[33 * N];
vector<station> stations(N);
int n, k, nodecnt = 0, root[maxf + 5];

int upd(int id, ll l, ll r, ll pos) {
  if (!id)
    id = ++nodecnt;
  ++t[id].sum;

  if (l == r)
    return id;

  ll mid = l + ((r - l) >> 1);
  if (pos <= mid)
    t[id].le = upd(t[id].le, l, mid, pos);
  else
    t[id].ri = upd(t[id].ri, mid + 1, r, pos);

  return id;
}

int query(int id, ll l, ll r, ll liml, ll limr) {
  if (!id || r < liml || l > limr)
    return 0;
  if (liml <= l && r <= limr)
    return t[id].sum;

  ll mid = l + ((r - l) >> 1);
  return query(t[id].le, l, mid, liml, limr) +
         query(t[id].ri, mid + 1, r, liml, limr);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for (int i = 1; i <= n; ++i)
    cin >> stations[i].x >> stations[i].r >> stations[i].f;

  sort(stations.begin() + 1, stations.begin() + n + 1);

  ll bad = 0;
  for (int i = 1; i <= n; ++i) {
    ll liml = stations[i].x - stations[i].r,
       limr = stations[i].x + stations[i].r;
    int curf = stations[i].f;

    int minf = max(curf - k, 1), max_f = min(maxf, curf + k);

    for (int f = minf; f <= max_f; ++f)
      if (root[f])
        bad += query(root[f], minx, maxx, liml, limr);

    root[curf] = upd(root[curf], minx, maxx, stations[i].x);
  }

  cout << bad;
}
