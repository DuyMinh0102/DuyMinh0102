// Source: https://codeforces.com/contest/2234/problem/D
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 19/07/2026 (DD/MM/YYYY).
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
int t;
ll n, k;
string s, z;

void solve() {
  cin >> n >> k >> s >> z;

  ll oa = 0, ob = 0, oc = 0;

  for (int i = 0; i < n; ++i) {
    int ba = s[i] - '0', bb = z[i] - '0', bc = ba ^ bb;

    oa += ba;
    ob += bb;
    oc += bc;
  }

  ll costa = oa * (n - oa), costb = ob * (n - ob), costc = oc * (n - oc);

  ll cnta = 0, cntb = 0, cntc = 0;

  if (k & 1) {
    ll block = ((1LL << k) + 1) / 3;
    cnta = cntb = cntc = block;
  } else {
    ll block = ((1LL << k) - 1) / 3;
    cnta = cntb = block + 1;
    cntc = block;
  }

  cout << cnta * costa + cntb * costb + cntc * costc << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
