// Source: https://codeforces.com/contest/676/problem/C
// Status: Unsolved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 01/07/2026 (DD/MM/YYYY).
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
int n, k, cnt[2];
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k >> s;

  int l = 0;
  int mx_len = 0;
  for (int r = 0; r <= n; ++r) {
    if (r < n)
      ++cnt[s[r] - 'a'];
    if (min(cnt[0], cnt[1]) <= k && r < n) {
      mx_len = max(mx_len, r - l + 1);
    } else {
      --cnt[s[l] - 'a'];
      ++l;
    }
  }

  cout << mx_len;
}
