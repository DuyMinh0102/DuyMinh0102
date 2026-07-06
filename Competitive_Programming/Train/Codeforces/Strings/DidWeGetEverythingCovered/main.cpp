// Source: https://codeforces.com/contest/1924/problem/A
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
int t, n, k, m;
string s;

void solve() {
  cin >> n >> k >> m >> s;
  vector<bool> check(k, false);
  int cnt = 0;
  string res = "";

  for (char c : s) {
    int id = c - 'a';
    if (!check[id]) {
      check[id] = true;
      ++cnt;

      if (cnt == k) {
        res += c;

        fill(check.begin(), check.end(), false);
        cnt = 0;
      }
    }
  }

  if ((int)res.size() >= n)
    cout << "YES\n";
  else {
    cout << "NO\n";

    char miss = 'a';
    for (int i = 0; i < k; ++i) {
      if (!check[i]) {
        miss = 'a' + i;
        break;
      }
    }

    res += miss;

    while ((int)res.size() < n)
      res += 'a';

    cout << res << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
