// Source: https://codeforces.com/contest/778/problem/A
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 12/07/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Config
#define pb push_back
#define ll long long

// Variables
string t, p;
vector<int> perm;
int n, m;

bool valid(int len) {
  vector<bool> rem(n, false);

  for (int i = 0; i < len; ++i)
    rem[perm[i] - 1] = true;

  int id = 0;
  for (int i = 0; i < n; ++i) {
    if (rem[i])
      continue;

    if (t[i] == p[id])
      ++id;

    if (id == m)
      return true;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t >> p;
  n = t.size();
  m = p.size();
  perm.resize(n);

  for (int &i : perm)
    cin >> i;

  int lo = 1, hi = n, ans = 0;

  while (lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);

    if (valid(mid)) {
      ans = max(ans, mid);
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  cout << ans;
}
