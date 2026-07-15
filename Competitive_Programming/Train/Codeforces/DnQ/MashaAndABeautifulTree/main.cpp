// Source: https://codeforces.com/contest/1741/problem/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 15/07/2026 (DD/MM/YYYY).
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
const int N = 300005;

// Variables
int t, m, p[N], ops = 0;
bool possible = true;

vector<int> dnq(int l, int r) {
  if (!possible)
    return {};

  if (r - l + 1 == 2) {
    if (abs(p[l] - p[r]) != 1) {
      possible = false;
      return {};
    }
    if (p[l] > p[r]) {
      ++ops;
      swap(p[l], p[r]);
    }

    return {p[l], p[r]};
  }

  int mid = l + ((r - l) >> 1);
  vector<int> left = dnq(l, mid), right = dnq(mid + 1, r);

  if (!possible)
    return {};

  if (abs(left.back() - right[0]) != 1 && abs(right.back() - left[0]) != 1) {
    possible = false;
    return {};
  }

  if (left[0] < right[0]) {
    for (int &i : right)
      left.pb(i);
    return left;
  }

  ++ops;
  for (int &i : left)
    right.pb(i);
  return right;
}

void solve() {
  ops = 0;
  possible = true;
  cin >> m;
  for (int i = 1; i <= m; ++i)
    cin >> p[i];

  if (m == 1) {
    cout << "0\n";
    return;
  }

  dnq(1, m);

  if (!possible)
    cout << "-1\n";
  else
    cout << ops << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();
}
