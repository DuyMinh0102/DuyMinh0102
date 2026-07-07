// Source: https://codeforces.com/contest/1451/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/07/2026 (DD/MM/YYYY).
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
string a, b;

void solve() {
  cin >> n >> k >> a >> b;
  int freq[26][2] = {0};
  for (char c : a)
    ++freq[c - 'a'][0];

  for (char c : b)
    ++freq[c - 'a'][1];

  for (int i = 0; i < 26; ++i) {
    if (freq[i][0] < freq[i][1] || abs(freq[i][0] - freq[i][1]) % k != 0) {
      cout << "No\n";
      return;
    }

    if (i < 25)
      freq[i + 1][0] += (freq[i][0] - freq[i][1]);
  }

  cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
