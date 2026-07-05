// Source: https://codeforces.com/contest/1332/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 05/07/2026 (DD/MM/YYYY).
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

  int ans = 0, b = n / k;

  for (int i = 0; i < k / 2; ++i) {
    vector<int> cnt(26, 0);

    for (int j = 0; j < b; ++j) {
      ++cnt[s[j * k + i] - 'a'];
      ++cnt[s[j * k + (k - i - 1)] - 'a'];
    }

    int mx_cnt = *max_element(cnt.begin(), cnt.end());
    ans += 2 * b - mx_cnt;
  }

  if (k % 2 != 0) {
    vector<int> cnt(26, 0);
    int i = k / 2;

    for (int j = 0; j < b; ++j)
      ++cnt[s[j * k + i] - 'a'];

    int mx_cnt = *max_element(cnt.begin(), cnt.end());
    ans += b - mx_cnt;
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
