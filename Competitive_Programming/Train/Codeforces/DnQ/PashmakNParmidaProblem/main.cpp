// Source: https://codeforces.com/contest/459/problem/D
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
const int N = 1000005;

// Variables
ll n, a[N], bit[N], suf[N];
map<int, ll> m;

void upd(int id, int val) {
  for (; id < N; id += (id & -id))
    bit[id] += val;
}

ll cnt(int id) {
  ll tmp = 0;
  for (; id > 0; id -= (id & -id))
    tmp += bit[id];

  return tmp;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = n; i > 1; --i) {
    ++m[a[i]];

    suf[i] = m[a[i]];
    upd(suf[i], 1);
  }

  m.clear();

  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    if (i > 1)
      upd(suf[i], -1);
    ++m[a[i]];

    ans += cnt(m[a[i]] - 1);
  }

  cout << ans << '\n';
}
