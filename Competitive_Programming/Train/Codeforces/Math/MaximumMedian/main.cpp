// Source: https://codeforces.com/contest/1201/problem/C
// Status: Solved
/*
Note: Given array, maximize median of array when sorted non-decreasingly with k
+1 operations.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/07/2026 (DD/MM/YYYY).
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
ll n, k;
vector<ll> a;

bool possible(ll target) {
  ll need = 0, mid = n / 2;

  for (int i = mid; i < n; ++i) {
    if (a[i] < target)
      need += target - a[i];

    if (need > k)
      return false;
  }

  return need <= k;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  a.resize(n);
  for (ll &i : a)
    cin >> i;

  sort(a.begin(), a.end());

  ll lo = a[n / 2], hi = a[n / 2] + k, ans = lo;

  while (lo <= hi) {
    ll mid = lo + ((hi - lo) >> 1);

    if (possible(mid)) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  cout << ans;
}
