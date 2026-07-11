// Source: https://codeforces.com/contest/1381/problem/A2
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 09/07/2026 (DD/MM/YYYY).
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
int t, n;
string a, b;

void solve() {
  cin >> n >> a >> b;

  if (n == 1)
    if (a[0] != b[0]) {
      cout << "1 1\n";
      return;
    }

  vector<int> instructs_a, instructs_b;

  for (int i = 1; i < n; ++i) {
    if (i != 0) {
      if (a[i] != a[i - 1])
        instructs_a.pb(i);
      if (b[i] != b[i - 1])
        instructs_b.pb(i);
    }

    if (i == n - 1) {
      if (a[i] != '0')
        instructs_a.pb(n);
      if (b[i] != '0')
        instructs_b.pb(n);
    }
  }

  cout << (int)instructs_a.size() + (int)instructs_b.size() << ' ';
  for (int i : instructs_a)
    cout << i << ' ';
  for (int i = (int)(instructs_b.size() - 1); i >= 0; --i)
    cout << instructs_b[i] << ' ';
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
