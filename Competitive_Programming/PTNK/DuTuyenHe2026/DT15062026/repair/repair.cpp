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
int t, n, k;

struct employee {
  ll l, m, r;
};
employee E[N];

bool cmp_sub1(const employee &a, const employee &b) { return a.l < b.l; }

void sub1() {
  sort(E + 1, E + k + 1, cmp_sub1);

  ll prev_r = E[1].r;
  for (int i = 2; i <= k; ++i) {
    if (E[i].l < prev_r)
      continue;
    else {
      if (E[i].l > prev_r) {
        cout << "NO";
        return;
      } else {
        prev_r = E[i].r + 1;
      }
    }
  }

  if (prev_r >= n)
    cout << "YES";
  else
    cout << "NO";
}

void sub23456() {}

void sub7() {
  ll mx1 = 0, mx2 = 0;

  for (int i = 1; i <= k; ++i) {
    if (E[i].m == 1)
      mx1 = max(mx1, E[i].r);
    else
      mx2 = min(mx2, E[i].l);
  }

  if (mx1 < mx2)
    cout << "NO";
  else
    cout << "YES";
}

void sub89() {}

void sub10() {}
void sub11() {}
void sub12() {}
void sub13() {}
void sub14() {}

void solve() {
  cin >> n >> k;

  bool only1n = true;
  bool s1 = true;
  bool s89 = true;
  bool mark[N] = {false};

  for (int i = 1; i <= k; ++i) {
    cin >> E[i].l >> E[i].m >> E[i].r;

    if (E[i].m != 1 || E[i].m != n && only1n)
      only1n = false;

    if (s1 && E[i].m != E[i].l)
      s1 = false;

    if (s89 && mark[E[i].m])
      s89 = false;
    mark[E[i].m] = true;
  }

  if (only1n)
    sub7();
  else if (s1)
    sub1();
  else if (s89)
    sub89();
  else if (n <= 150 && k <= 500)
    sub23456();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
