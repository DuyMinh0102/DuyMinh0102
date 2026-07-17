// Source: https://codeforces.com/contest/1795/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 17/07/2026 (DD/MM/YYYY).
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

// Variables
ll t, n, b[N], rem[N], bit[N], a[N], pref[N];

void upd(int id, ll val) {
  for (; id <= n; id += (id & -id))
    bit[id] += val;
}

ll get(int id) {
  ll sum = 0;
  for (; id > 0; id -= (id & -id))
    sum += bit[id];
  return sum;
}

void solve() {
  cin >> n;
  for (int i = 0; i <= n + 2; ++i)
    bit[i] = rem[i] = pref[i] = 0;

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    pref[i] = pref[i - 1] + b[i];
  }

  for (int i = 1; i <= n; ++i) {
    ll target = a[i] + pref[i - 1];
    int k = upper_bound(pref + i, pref + n + 1, target) - pref;

    if (i <= k - 1) {
      upd(i, 1);
      if (k <= n)
        upd(k, -1);
    }

    if (k <= n) {
      ll consume = pref[k - 1] - pref[i - 1];
      rem[k] += a[i] - consume;
    }
  }

  for (int i = 1; i <= n; ++i)
    cout << (ll)(get(i) * b[i]) + rem[i] << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
