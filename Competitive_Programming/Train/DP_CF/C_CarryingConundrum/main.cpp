// Source: https://codeforces.com/contest/1567/problem/C
// Status: Unsolved
/*
Note: Alice performs addition but carries two columns to the right instead of
one. Find the number of ordered pairs of positive intergers (a, b) such that
their Alice-addition equals n.

Solution: Carry skips a column -> digits at even pos (0, 2, 4,..) and odd (1, 3,
5,..) from the right operate completely independently. So we split n into two
separate numbers. A: formed by even-pos digits B: formed by odd-pos digits
Number of non-neg pairs that sum to A is (A + 1) and for B is (B + 1)
respectively. Total: (A + 1) * (B + 1) The problem requires both: substract 2 to
exclude invalid pairs (0, n) and (n, 0)

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 23/05/2026 (DD/MM/YYYY).
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
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> s;
    ll a = 0, b = 0, p1 = 1, p2 = 1;

    for (int i = s.size() - 1; i >= 0; --i) {
      ll d = s[i] - '0';

      if ((s.size() - i - 1) % 2 == 0) {
        a += d * p1;
        p1 *= 10;
      } else {
        b += d * p2;
        p2 *= 10;
      }
    }

    ll ans = 1LL * (a + 1) * (b + 1) - 2;
    cout << ans << '\n';
  }
}
