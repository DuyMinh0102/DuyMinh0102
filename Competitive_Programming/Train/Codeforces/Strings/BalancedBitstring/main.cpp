// Source: https://codeforces.com/contest/1404/problem/A
// Status: Solved
/*
Note: Given a string contains only '0', '1', and '?'. Determine if there's a way
to replace '?'s with '0' or '1' so that every k-sized substring has an equal
amount of 0s and 1s. k is even

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 04/07/2026 (DD/MM/YYYY).
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
string s;

void solve() {
  cin >> n >> k >> s;

  bool possible = true;

  for (int i = 0; i < k; ++i) {
    char f_char = '?';

    for (int j = i; j < n; j += k) {
      if (s[j] == '?')
        continue;

      if (f_char != '?' && s[j] != f_char) {
        possible = false;
        break;
      }

      f_char = s[j];
    }

    if (!possible)
      break;
    s[i] = f_char;
  }

  if (!possible) {
    cout << "NO\n";
    return;
  }

  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < k; ++i) {
    if (s[i] == '0')
      ++cnt0;
    else if (s[i] == '1')
      ++cnt1;
  }

  if (cnt0 <= k / 2 && cnt1 <= k / 2)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
