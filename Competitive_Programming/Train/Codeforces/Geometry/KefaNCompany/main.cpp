// Source: https://codeforces.com/problemset/problem/580/B
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 18/08/2026 (DD/MM/YYYY).
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
  ll x, val;

  Event(ll _x, ll _val) : x(_x), val(_val) {}

  bool operator<(const Event &other) const {
    if (x != other.x)
      return x < other.x;
    return val < other.val;
  }
};
vector<Event> events;
vector<ll> ans;
int n;
ll d;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> d;

  ans.resize(n + 1);
  events.reserve((size_t)2 * n);

  for (int i = 0; i < n; ++i) {
    ll m, s;
    cin >> m >> s;

    events.pb(Event(m, s));
    events.pb(Event(m + d, -s));
  }
  sort(events.begin(), events.end());

  ll current_val = 0, mx_val = 0;
  for (const Event &e : events) {
    current_val += e.val;

    mx_val = max(mx_val, current_val);
  }

  cout << mx_val;
}
