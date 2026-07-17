// Source: https://codeforces.com/contest/448/problem/C
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

// Variables
int n, a[5005];

int cnt(int l, int r, int sub) {
  if (l > r)
    return 0;

  int id = l;
  for (int i = l + 1; i <= r; ++i)
    if (a[i] < a[id])
      id = i;

  int ops = (a[id] - sub) + cnt(l, id - 1, a[id]) + cnt(id + 1, r, a[id]);

  return min(ops, r - l + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  cout << cnt(1, n, 0);
}
