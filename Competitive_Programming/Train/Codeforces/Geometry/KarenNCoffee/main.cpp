// Source: https://codeforces.com/contest/816/problem/B
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 15/08/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;
const int MXVAL = 200000;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Variables
struct Event {
  int temp, val;

  bool operator<(const Event &other) const { return temp < other.temp; }
};
vector<Event> e;
vector<int> pref(MXVAL + 5, 0);
int n, k, q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k >> q;

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;

    e.pb({l, 1});
    e.pb({r + 1, -1});
  }

  sort(e.begin(), e.end());

  int active = 0, id = 0, num = e.size();

  for (int t = 1; t <= MXVAL; ++t) {
    while (id < num && e[id].temp == t) {
      active += e[id].val;
      ++id;
    }

    pref[t] = pref[t - 1] + (int)((active >= k) ? 1 : 0);
  }

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;

    cout << pref[b] - pref[a - 1] << '\n';
  }
}
