// Source: https://codeforces.com/contest/1374/problem/D
// Status: Solved
/*
Note: Two types of operations:
x += 1
a_i += x (each a_i can only be ince by x once)
Output minimum amount of ops so every a_i % k == 0

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/07/2026 (DD/MM/YYYY).
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
ll t, n, k;

void solve() {
  cin >> n >> k;
  map<ll, ll> freq;

  ll op = -1;

  for (int i = 1; i <= n; ++i) {
    ll x;
    cin >> x;
    if (x % k != 0) {
      ll rem = k - (x % k);
      ++freq[rem];
      op = max(op, rem + (freq[rem] - 1) * k);
    }
  }

  if (op == -1)
    cout << 0;
  else
    cout << op + 1;
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
