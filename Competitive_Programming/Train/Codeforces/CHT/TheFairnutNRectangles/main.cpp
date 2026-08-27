// Source: https://codeforces.com/contest/1083/problem/E
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
const ll INF = 2e18;
const int MAXN = 1000000;

// Variables
struct Line {
  ll m, c;
  ll eval(ll x) const { return m * x + c; }
};

struct Rect {
  ll x, y, a;
  bool operator<(const Rect &other) const { return x < other.x; }
};

struct LiChaoTree {
  int N;
  vector<ll> X;
  vector<Line> tree;

  LiChaoTree(const vector<ll> &coords) : X(coords) {
    N = X.size();
    tree.assign(4 * N, {0, -INF});
  }

  void addline(Line newline, int node, int l, int r) {
    int mid = l + ((r - l) >> 1);
    bool left_better = newline.eval(X[l]) > tree[node].eval(X[l]),
         mid_better = newline.eval(X[mid]) > tree[node].eval(X[mid]);

    if (mid_better)
      swap(tree[node], newline);

    if (l == r)
      return;

    if (left_better != mid_better)
      addline(newline, node << 1, l, mid);
    else
      addline(newline, node << 1 | 1, mid + 1, r);
  }

  void add(ll m, ll c) {
    if (N == 0)
      return;

    addline({m, c}, 1, 0, N - 1);
  }

  ll query(int pos, int node, int l, int r) {
    ll res = tree[node].eval(X[pos]);
    if (l == r)
      return res;

    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
      return max(res, query(pos, node << 1, l, mid));
    else
      return max(res, query(pos, node << 1 | 1, mid + 1, r));
  }

  ll query_val(ll x) {
    int pos = lower_bound(X.begin(), X.end(), x) - X.begin();
    return query(pos, 1, 0, N - 1);
  }
};
int n;
vector<Rect> rects;
vector<ll> Y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  rects.resize(n);
  Y.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> rects[i].x >> rects[i].y >> rects[i].a;
    Y[i] = rects[i].y;
  }

  sort(rects.begin(), rects.end());

  sort(Y.begin(), Y.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());

  LiChaoTree tree(Y);

  tree.add(0, 0);

  ll ans = 0;

  for (int i = 0; i < n; ++i) {
    ll best_prev = tree.query_val(rects[i].y);
    ll dp = rects[i].x * rects[i].y - rects[i].a + best_prev;

    ans = max(ans, dp);

    tree.add(-rects[i].x, dp);
  }

  cout << ans;
}
