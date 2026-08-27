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
const int MAXN = 200000;
const ll MOD = 1000000007;
const ll INF = 2e18;

// Variables
struct Doll {
  ll out, in;
  bool operator<(const Doll &other) const { return out < other.out; }
};

struct Node {
  ll mn, cnt;
};

Node combine(Node a, Node b) {
  if (a.mn < b.mn)
    return a;
  if (b.mn < a.mn)
    return b;

  return {a.mn, (a.cnt + b.cnt) % MOD};
}

struct SegmentTree {
  int N;
  vector<Node> tree;

  SegmentTree(int _n) : N(_n), tree(4 * _n, {INF, 0}) {}

  void upd(int k, int l, int r, int pos, Node val) {
    if (l == r) {
      tree[k] = combine(tree[k], val);
      return;
    }

    int mid = l + ((r - l) >> 1);
    if (pos <= mid)
      upd(k << 1, l, mid, pos, val);
    else
      upd(k << 1 | 1, mid + 1, r, pos, val);

    tree[k] = combine(tree[k << 1], tree[k << 1 | 1]);
  }

  Node query(int k, int l, int r, int liml, int limr) {
    if (liml > r || limr < l)
      return {INF, 0};
    if (liml <= l && r <= limr)
      return tree[k];

    int mid = l + ((r - l) >> 1);
    return combine(query(k << 1, l, mid, liml, limr),
                   query(k << 1 | 1, mid + 1, r, liml, limr));
  }
};

int n;
vector<Doll> dolls;
vector<ll> outs, dp, cnt;

int get_id(ll val) {
  return lower_bound(outs.begin(), outs.end(), val) - outs.begin();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  dolls.resize(n);
  dp.resize(n);
  cnt.resize(n);

  ll mx_in = 0;

  for (int i = 0; i < n; ++i) {
    cin >> dolls[i].out >> dolls[i].in;

    mx_in = max(mx_in, dolls[i].in);
    outs.pb(dolls[i].out);
  }

  sort(dolls.begin(), dolls.end());

  sort(outs.begin(), outs.end());
  outs.erase(unique(outs.begin(), outs.end()), outs.end());
  int m = outs.size();

  SegmentTree t(m + 1);
  t.upd(1, 0, m, 0, {0, 1});

  for (int i = 0; i < n; ++i) {
    int r = upper_bound(outs.begin(), outs.end(), dolls[i].in) - outs.begin();

    Node best = t.query(1, 0, m, 0, r);

    dp[i] = dolls[i].in + best.mn;
    cnt[i] = best.cnt;

    int id = get_id(dolls[i].out) + 1;
    t.upd(1, 0, m, id, {dp[i] - dolls[i].out, cnt[i]});
  }

  ll mn_space = INF, ans = 0;

  for (int i = 0; i < n; ++i) {
    if (dolls[i].out > mx_in) {
      if (dp[i] < mn_space) {
        mn_space = dp[i];
        ans = cnt[i];
      } else if (dp[i] == mn_space) {
        ans = (ans + cnt[i]) % MOD;
      }
    }
  }

  cout << ans;
}
