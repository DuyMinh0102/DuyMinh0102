// Source: https://codeforces.com/contest/1915/problem/F
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 13/07/2026 (DD/MM/YYYY).
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
struct segment {
  int a, b;

  bool operator<(const segment &other) const { return a < other.a; }
};
vector<segment> se;
ll ans;

vector<int> cnt(int l, int r) {
  if (l == r)
    return {se[l].b};

  int mid = l + ((r - l) >> 1);

  vector<int> left = cnt(l, mid), right = cnt(mid + 1, r);

  int i = 0, j = 0;
  int len_l = left.size(), len_r = right.size();

  vector<int> tmp;
  while (i < len_l || j < len_r) {
    if (i < len_l && (left[i] < right[j] || j == len_r)) {
      tmp.pb(left[i]);
      ++i;
    } else {
      tmp.pb(right[j]);
      ++j;
      ans += (len_l - i);
    }
  }

  return tmp;
}

void solve() {
  ans = 0;
  cin >> n;
  se.resize(n + 1);

  for (int i = 1; i <= n; ++i)
    cin >> se[i].a >> se[i].b;

  sort(se.begin() + 1, se.begin() + n + 1);

  cnt(1, n);

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
