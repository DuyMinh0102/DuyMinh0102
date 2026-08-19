// Source: https://codeforces.com/contest/1400/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 02/08/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;
string s;
int t, x;

void solve() {
  cin >> s >> x;

  int n = s.length();

  string w(n, '1');

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (i - x >= 0)
        w[i - x] = '0';

      if (i + x < n)
        w[i + x] = '0';
    }
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      bool can_be_one = false;
      if (i - x >= 0 && w[i - x] == '1')
        can_be_one = true;

      if (i + x < n && w[i + x] == '1')
        can_be_one = true;

      if (!can_be_one) {
        cout << -1 << "\n";
        return;
      }
    }
  }

  cout << w << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while (t--)
    solve();

  return 0;
}
