// Source: https://codeforces.com/contest/2146/problem/D1
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 18/07/2026 (DD/MM/YYYY).
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
int t, l, r, n;
ll total;
vector<int> a;

void solve(int cur) {
  if (cur < 0)
    return;

  int hi_bit = -1;
  for (int b = 20; b >= 0; --b) {
    if ((cur >> b) & 1) {
      hi_bit = b;
      break;
    }
  }

  int mask = 0;
  if (hi_bit != -1)
    mask = (1 << (hi_bit + 1)) - 1;

  int split = mask ^ cur;

  for (int i = split; i <= cur; ++i) {
    a[i] = mask ^ i;
    total += mask;
  }

  solve(split - 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> l >> r;
    int n = r - l + 1;
    a.assign(n, 0);
    total = 0;

    solve(r);

    cout << total << '\n';
    for (int i = 0; i < n; ++i)
      cout << a[i] << ' ';
    cout << '\n';
  }
}
