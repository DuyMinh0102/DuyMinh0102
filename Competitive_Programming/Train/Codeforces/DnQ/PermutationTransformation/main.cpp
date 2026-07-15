// Source: https://codeforces.com/contest/1490/problem/D
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

// Variables
int t, n;
vector<int> depth;

void solve(int l, int r, int d, vector<int> &a) {
  if (l > r)
    return;
  if (l == r) {
    if (depth[l] == -1)
      depth[l] = d;
    return;
  }

  int id = l;
  for (int i = l + 1; i < r; ++i) {
    if (a[i] > a[id])
      id = i;
  }

  depth[id] = d;
  solve(l, id, d + 1, a);
  solve(id + 1, r, d + 1, a);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    depth.resize(n, -1);

    for (int &i : a)
      cin >> i;

    solve(0, n, 0, a);

    for (int i = 0; i < n; ++i)
      cout << depth[i] << ' ';
    cout << '\n';
  }
}
