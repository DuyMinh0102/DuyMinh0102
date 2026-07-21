// Source: https://codeforces.com/problemset/problem/813/E
// Status: Solved
/*
Note:

Hire n warriors, i-th warrior is of type a-i.
goal: create balanced army -> each type of warrior, not more than k of them is
inside of the army

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
int n, k, q;
int a[N], prevk[N];
vector<vector<int>> Pos(N);
vector<int> root(N);

struct Node {
  int sum, le, ri;
};
Node tree[40 * N];
int cnt = 0;

int init(int l, int r) {
  int id = ++cnt;
  tree[id].sum = 0;
  if (l == r)
    return id;

  int mid = l + ((r - l) >> 1);
  tree[id].le = init(l, mid);
  tree[id].ri = init(mid + 1, r);
  return id;
}

int update(int prev, int l, int r, int pos, int val) {
  int id = ++cnt;
  tree[id] = tree[prev];
  tree[id].sum += val;

  if (l == r)
    return id;

  int mid = l + ((r - l) >> 1);
  if (pos <= mid)
    tree[id].le = update(tree[prev].le, l, mid, pos, val);
  else
    tree[id].ri = update(tree[prev].ri, mid + 1, r, pos, val);

  return id;
}

int query(int id, int l, int r, int liml, int limr) {
  if (l > limr || r < liml)
    return 0;
  if (liml <= l && r <= limr)
    return tree[id].sum;

  int mid = l + ((r - l) >> 1);
  return query(tree[id].le, l, mid, liml, limr) +
         query(tree[id].ri, mid + 1, r, liml, limr);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    Pos[a[i]].pb(i);

    if ((int)Pos[a[i]].size() > k)
      prevk[i] = Pos[a[i]][Pos[a[i]].size() - k - 1];
    else
      prevk[i] = 0;
  }

  root[0] = init(0, n);

  for (int i = 1; i <= n; ++i)
    root[i] = update(root[i - 1], 0, n, prevk[i], 1);

  int last = 0;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;

    x = (x + last) % n + 1;
    y = (y + last) % n + 1;
    if (x > y)
      swap(x, y);

    int valid = query(root[y], 0, n, 0, x - 1);
    int valid_before_l = query(root[x - 1], 0, n, 0, x - 1);

    int ans = valid - valid_before_l;

    last = ans;

    cout << ans << '\n';
  }
}
