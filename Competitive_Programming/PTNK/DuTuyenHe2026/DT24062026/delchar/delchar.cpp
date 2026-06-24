// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
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
string s, t;
bool possible = false;
bool appeared[26];

void solve() {
  cin >> s >> t;

  if (s[0] != t[0])
    return;

  for (char c : t) {
    appeared[c - 'a'] = true;
  }

  int lst_even = 0;
  vector<char> v;
  for (int i = 0; i < s.size(); ++i) {
    ++lst_even;
    if (i & 1)
      lst_even = 1;
    v.pb(s[i]);

    if (!appeared[s[i] - 'a']) {
      while (lst_even > 0 && !v.empty()) {
        --lst_even;
        v.pop_back();
      }
    }
  }

  string res = "";
  for (char c : v)
    res += c;

  int id = 0;
  string ans = "";
  for (int i = 0; i < t.size(); ++i) {
    while (res[id] != t[i])
      ++id;
    if (t[i] == res[id])
      ans += res[id];
  }

  cerr << ans;
  if (ans == t)
    possible = true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("delchar.inp", "r", stdin);
  freopen("delchar.out", "w", stdout);

  solve();

  if (possible)
    cout << "YES";
  else
    cout << "NO";
}
