// Source: https://codeforces.com/contest/1950/problem/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 06/07/2026 (DD/MM/YYYY).
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
string s;

bool valid(const string &st, const string &k, int &len) {
  int diff = 0;
  for (int i = 0; i < n; ++i) {
    if (st[i] != k[i % len]) {
      ++diff;
      if (diff > 1)
        return false;
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> s;

    vector<int> div;
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        div.pb(i);
        if (i * i != n)
          div.pb(n / i);
      }
    }

    sort(div.begin(), div.end());

    for (int l : div) {
      string a = s.substr(0, l);
      if (valid(s, a, l)) {
        cout << l << '\n';
        break;
      }

      if (n / l >= 2) {
        string b = s.substr(l, l);
        if (valid(s, b, l)) {
          cout << l << '\n';
          break;
        }
      }
    }
  }
}
