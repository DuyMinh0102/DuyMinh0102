// Source: https://codeforces.com/contest/1000/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 17/08/2026 (DD/MM/YYYY).
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
struct Event {
  ll x, type;

  Event(ll _x, ll _type) : x(_x), type(_type) {}

  bool operator<(const Event &other) const { return x < other.x; }
};
vector<Event> events;
vector<ll> ans;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  events.reserve(2 * n);
  ans.resize(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;

    events.pb({l, 1});
    events.pb({r + 1, -1});
  }

  sort(events.begin(), events.end());

  ll active = 0, prev = events[0].x;

  for (const Event &e : events) {
    ll curr = e.x, delta = e.type;

    if (active > 0)
      ans[active] += (curr - prev);

    active += delta;
    prev = curr;
  }

  for (int i = 1; i <= n; ++i)
    cout << ans[i] << ' ';
}
