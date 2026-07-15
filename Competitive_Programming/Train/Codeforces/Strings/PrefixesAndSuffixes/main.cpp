// Source: https://codeforces.com/contest/432/problem/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 12/07/2026 (DD/MM/YYYY).
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
vector<int> pi, cnt, len;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int n = s.size();
  pi.resize(n, 0);
  cnt.resize(n + 1, 1);

  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];

    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];

    if (s[i] == s[j])
      ++j;

    pi[i] = j;
  }

  for (int i = n - 1; i >= 0; --i)
    cnt[pi[i]] += cnt[i + 1];

  int le = n;
  while (le > 0) {
    len.pb(le);
    le = pi[le - 1];
  }

  sort(len.begin(), len.end());
  cout << len.size() << '\n';
  for (int l : len)
    cout << l << ' ' << cnt[l] << '\n';
}
