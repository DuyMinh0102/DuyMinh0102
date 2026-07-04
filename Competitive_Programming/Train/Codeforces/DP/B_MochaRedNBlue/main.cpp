// Source: https://codeforces.com/problemset/problem/1559/B
// Status: Solved
/*
Note: Avoid having two similar characters next to each other

Solution:
1. Check: if full '?', simply construct alternatively between B and R
2. Greedily fill the '?' from left, then from right.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;
int t, n;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> t;

  while (t--) {
    cin >> n;
    string s;
    int check = 0;
    cin >> s;

    for (int i = 0; i < n; ++i)
      check += (s[i] != '?');

    if (!check)
      s[0] = 'R';

    for (int i = 1; i < n; ++i) {
      if (s[i] == '?' && s[i - 1] != '?') {
        s[i] = s[i - 1] ^ 'R' ^ 'B';
      }
    }

    for (int i = n; i >= 0; --i) {
      if (s[i] == '?' && s[i + 1] != '?') {
        s[i] = s[i + 1] ^ 'R' ^ 'B';
      }
    }

    cout << s << '\n';
  }
}
