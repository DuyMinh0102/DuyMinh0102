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
#define db double
const int N = 50005;

// Variables
int n, cnt[N];
ll p, a[N], dp[N];

struct line {
  ll m, b;
  int c;
  ll val(ll x) { return m * x + b; }
};
deque<line> dq;

bool is_bad(line l1, line l2, line l3) {
  return (db)(l2.b - l1.b) * (l2.m - l3.m) >= (db)(l3.b - l2.b) * (l1.m - l2.m);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> p;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  dq.pb({0, 0, 0});

  for (int i = 1; i <= n; ++i) {
    while (dq.size() >= 2 && dq[0].val(a[i]) >= dq[1].val(a[i]))
      dq.pop_front();

    dp[i] = dq[0].val(a[i]) + a[i] * a[i] + p;
    cnt[i] = dq[0].c + 1;

    line newline = {-2 * a[i], dp[i] + a[i] * a[i], cnt[i]};
    while (dq.size() >= 2 && is_bad(dq[dq.size() - 2], dq.back(), newline))
      dq.pop_back();

    dq.pb(newline);
  }

  cout << dp[n] << ' ' << cnt[n];
}
