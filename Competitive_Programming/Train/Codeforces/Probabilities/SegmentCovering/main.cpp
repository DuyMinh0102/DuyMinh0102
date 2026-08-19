// Source: https://codeforces.com/problemset/problem/2125/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 31/07/2026 (DD/MM/YYYY).
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
const ll MOD = 998244353;

// Variables
struct segment {
  int l, r;
  ll p, q;
};
vector<segment> se;
int n, m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    int l, r;
    ll p, q;
    cin >> l >> r >> p >> q;

    se.push_back({l, r, p, q});
  }
}
