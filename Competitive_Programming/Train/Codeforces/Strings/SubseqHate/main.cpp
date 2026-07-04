// Source: https://codeforces.com/contest/1363/problem/B
// Status: Unsolved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 30/06/2026 (DD/MM/YYYY).
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
string s;
int cnt[2];

void solve() {
  cin >> s;
  cnt[0] = cnt[1] = 0;

  int n = s.size();
  for (int i = 0; i < n; ++i)
    ++cnt[s[i] - '0'];

  if (max(cnt[0], cnt[1]) == n) {
    cout << 0 << '\n';
    return;
  }

  int ans = n, pref0 = 0, pref1 = 0;

  for (int i = 0; i <= n; ++i) {
    ans = min({ans, pref0 + cnt[1] - pref1, pref1 + cnt[0] - pref0});

    if (i < n) {
      if (s[i] == '0')
        ++pref0;
      else
        ++pref1;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--)
    solve();
}
