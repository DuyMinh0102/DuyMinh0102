// Source: https://codeforces.com/contest/2128/problem/D
// Status: Solved
/*
Note: Given a permutation p_1, p_2,...p_n where max(p_i, p_{i + 1}) > p_{i + 2}
Calculate the sum of length of the longest decreasing subsequence of all pairs 1
<= l <= r <= n;

Solution: Because of the constraints, max(p_i, p_{i + 1}) > p_{i + 2} we are
basically guaranteed to have a decreasing subsequence of length at least n / 2
for an array of length n.
So, we assume if the element i is inside of a decreasing subsequence, it will
appear in i * (n - i + 1) subsequence. Then we calculate the amount of ascents
(p_i < p_{i + 1}) and substract them, these ascents will appear in i * (n - i)
subsequence Output total.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 22/05/2026 (DD/MM/YYYY).
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
const int N = 500005;

// Variables
int n, t;
int p[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> p[i];

  ll total = 0;
  for (ll i = 1; i <= n; ++i) {
    total += i * (n - i + 1);
  }

  for (ll i = 1; i < n; ++i) {
    if (p[i] < p[i + 1])
      total -= i * (n - i);
  }

  cout << total << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    solve();
  }
}
