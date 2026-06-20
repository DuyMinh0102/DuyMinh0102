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
int n, q;
ll h[N], cur_H[N];
struct query {
  ll l, r, h;
};
query Q[N];
ll sum = 0;

void sub1() {
  for (int i = 0; i < q; ++i) {
    ll range = Q[i].r - Q[i].l + 1;
    sum = sum - cur_H[1] * range + min(Q[i].h, h[1]) * range;
    cur_H[1] = min(Q[i].h, h[1]);
    cout << sum << '\n';
  }
}

void sub2() {}

void sub345() {
  for (int i = 0; i < q; ++i) {
    for (int j = Q[i].l; j <= Q[i].r; ++j) {
      sum = sum - cur_H[j] + min(h[j], Q[i].h);
      cur_H[j] = min(h[j], Q[i].h);
    }
    cout << sum << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("decor.inp", "r", stdin);
  freopen("decor.out", "w", stdout);

  cin >> n >> q;

  bool allequal = true, nondec = true, rng10 = true;

  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    cur_H[i] = h[i];
    if (i > 1) {
      if (h[i] != h[i - 1] && allequal)
        allequal = false;
      if (h[i] < h[i - 1])
        nondec = false;
    }
    sum += h[i];
  }

  for (int i = 0; i < q; ++i) {
    cin >> Q[i].l >> Q[i].r >> Q[i].h;

    if (Q[i].r - Q[i].l > 10 && rng10)
      rng10 = false;
  }

  if (allequal)
    sub1();
  else if (n <= 2000 && q <= 2000 || rng10)
    sub345();
  else if (nondec)
    sub2();
}
