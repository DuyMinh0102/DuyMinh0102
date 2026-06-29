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

void solve() {
  cin >> s >> t;

  if (s[0] != t[0])
    return;

  int id = 0;
  for (char c : s) {
    if (c == t[id]) {
      ++id;
      continue;
    }

    if (possible)
      continue;

    if (id % 2 == 1) {
      possible = true;
    } else {
      possible = true;
      if (c != t[id])
        --id;
    }
  }

  if (id == t.size())
    cout << "YES";
  else
    cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("delchar.inp", "r", stdin);
  freopen("delchar.out", "w", stdout);

  solve();
}
