// Source: https://codeforces.com/contest/2053/problem/C
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
int t, n, k;

ll solve(ll l, ll r) {
  if (l > r)
    return 0;
  if (r - l + 1 < k)
    return 0;

  ll mid = l + ((r - l) >> 1);
  if ((r - l + 1) & 1) {
    return mid + ((r != l) ? solve(l, mid - 1) + solve(mid + 1, r) : 0);
  }

  return solve(l, mid) + solve(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> k;

    cout << solve(1, n) << '\n';
  }
}
