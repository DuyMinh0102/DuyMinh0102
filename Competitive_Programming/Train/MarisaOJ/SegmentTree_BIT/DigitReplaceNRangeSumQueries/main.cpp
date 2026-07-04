// Source: https://marisaoj.com/problem/721
// Status: Solved
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
const int N = 1e5 + 5;

// Variables
int n, q;
int a[N];

struct node {
  ll w[10], lazy[10];
  node() {
    for (int i = 0; i < 10; ++i) {
      w[i] = 0;
      lazy[i] = i;
    }
  }
};
node t[4 * N];

void pull(int k) {
  for (int i = 0; i < 10; ++i) {
    t[k].w[i] = t[k << 1].w[i] + t[k << 1 | 1].w[i];
  }
}

void apply(int k, ll mp[10]) {
  ll n_mp[10] = {0};

  for (int i = 0; i < 10; ++i)
    n_mp[mp[i]] += t[k].w[i];

  for (int i = 0; i < 10; ++i) {
    t[k].w[i] = n_mp[i];
    t[k].lazy[i] = mp[t[k].lazy[i]];
  }
}

void build(int k, int l, int r) {
  if (l > r)
    return;
  if (l == r) {
    ll x = a[l], mul = 1;
    while (x > 0) {
      int cur = x % 10;
      t[k].w[cur] += mul;
      x /= 10;
      mul *= 10;
    }
    return;
  }

  int mid = l + ((r - l) >> 1);
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  pull(k);
}

void push(int k) {
  bool haslazy = false;
  for (int i = 0; i < 10; ++i) {
    if (t[k].lazy[i] != 0) {
      haslazy = true;
      break;
    }
  }
  if (!haslazy)
    return;

  apply(k << 1, t[k].lazy);
  apply(k << 1 | 1, t[k].lazy);

  for (int i = 0; i < 10; ++i) {
    t[k].lazy[i] = i;
  }
}

void update(int k, int l, int r, int u, int v, int x, int y) {
  if (l > v || r < u)
    return;
  if (u <= l && r <= v) {
    ll mp[10];
    for (int i = 0; i < 10; ++i)
      mp[i] = i;
    mp[x] = y;

    apply(k, mp);
    return;
  }

  push(k);
  int mid = l + ((r - l) >> 1);
  update(k << 1, l, mid, u, v, x, y);
  update(k << 1 | 1, mid + 1, r, u, v, x, y);
  pull(k);
}

ll query(int k, int l, int r, int u, int v) {
  if (l > v || r < u)
    return 0;
  if (u <= l && r <= v) {
    ll sum = 0;
    for (ll i = 1; i < 10; ++i) {
      sum += i * t[k].w[i];
    }
    return sum;
  }

  push(k);
  int mid = l + ((r - l) >> 1);
  return query(k << 1, l, mid, u, v) + query(k << 1 | 1, mid + 1, r, u, v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  build(1, 1, n);

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int l, r, x, y;
      cin >> l >> r >> x >> y;

      update(1, 1, n, l, r, x, y);
    } else {
      int l, r;
      cin >> l >> r;

      cout << query(1, 1, n, l, r) << '\n';
    }
  }
}
