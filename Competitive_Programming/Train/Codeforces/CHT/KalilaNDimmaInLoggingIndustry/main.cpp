// Source: https://codeforces.com/problemset/problem/319/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 25/08/2026 (DD/MM/YYYY).
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

// Variables
struct Line {
  ll m, c;

  ll eval(ll x) const { return m * x + c; }
};

bool redundant(const Line &l1, const Line &l2, const Line &l3) {
  return (__int128)(l3.c - l2.c) * (l1.m - l2.m) <=
         (__int128)(l2.c - l1.c) * (l2.m - l3.m);
}
vector<ll> a, b, dp;
vector<Line> hull;
int n, ptr = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  a.resize(n);
  b.resize(n);
  dp.resize(n, 0);

  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];

  dp[0] = 0;
  hull.pb({b[0], dp[0]});

  for (int i = 1; i < n; ++i) {
    while (ptr + 1 < (int)hull.size() &&
           hull[ptr + 1].eval(a[i]) <= hull[ptr].eval(a[i]))
      ++ptr;

    dp[i] = hull[ptr].eval(a[i]);

    Line newline = {b[i], dp[i]};

    while (hull.size() >= 2 &&
           redundant(hull[hull.size() - 2], hull.back(), newline))
      hull.pop_back();
    hull.pb(newline);

    if (ptr >= (int)hull.size()) {
      ptr = (int)hull.size() - 1;
    }
  }

  cout << dp[n - 1];
}
