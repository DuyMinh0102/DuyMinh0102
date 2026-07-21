// Source: https://codeforces.com/problemset/problem/226/E
// Status: Unsolved
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
const int N = 200005;
const ll INF = 2e18;

// Variables
int n, m, tolnode = 0;
int a[N], rootid[N], cur[N * 20];
ll val[N * 20], le[N * 20], ri[N * 20];
bool atk[N];

ll init(int id, int l, int r) {
  ++tolnode;

  if (l == r) {
    val[id] = a[l];
    return a[l];
  }

  le[id] = (id << 1), ri[id] = (id << 1 | 1);

  int mid = l + ((r - l) >> 1);

  val[id] = init(le[id], l, mid) + init(ri[id], mid + 1, r);
  return val[id];
}

void upd(int id, int l, int r, int pos, ll v) {
  if (l == r) {
    ++tolnode;
    val[tolnode] = v;
    return;
  }

  ++tolnode;
  int newid = tolnode;

  cur[id] = newid;
  int mid = l + ((r - l) >> 1);

  if (pos <= mid) {
    upd(id << 1, l, mid, pos, v);

    le[newid] = newid + 1;
    ri[newid] = cur[id << 1 | 1];
  } else {
    upd(id << 1 | 1, mid + 1, r, pos, v);
    le[newid] = cur[id << 1];
    ri[newid] = newid + 1;
  }

  val[newid] = val[le[newid]] + val[ri[newid]];
}

ll get(int id, int l, int r, int liml, int limr) {
  if (limr < l || liml > r)
    return 0;
  if (liml <= l && r <= limr)
    return val[id];

  int mid = l + ((r - l) >> 1);
  return get(le[id], l, mid, liml, limr) + get(ri[id], mid + 1, r, liml, limr);
}

int cnt_que = 0;

void update(int p, ll v) {
  ++cnt_que;
  rootid[cnt_que] = tolnode + 1;
  upd(1, 1, n, p, v);
}

ll ans(int l, int r, int k) { return get(rootid[k], 1, n, l, r); }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  init(1, 1, n);

  cin >> m;
  while (m--) {
    int t;
    cin >> t;

    if (t == 1) {
      int c;
      cin >> c;

      atk[c] = true;
    } else {
      int a, b, k, y;
      cin >> a >> b >> k >> y;
    }
  }
}
