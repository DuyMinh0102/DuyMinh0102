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
int t;
ll n;

ll cnt5(ll x) {
  ll ans = 0;
  for (ll i = 5; i <= x; i *= 5) {
    ans += x / i;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("nfactor.inp", "r", stdin);
  freopen("nfactor.out", "w", stdout);

  cin >> t;

  while (t--) {
    cin >> n;
    bool possible = false;

    ll m = 1000000000000000000;
    ll r = m, l = 1;
    while (l <= r) {
      ll mid = l + (r - l) / 2;
      ll cnt = cnt5(mid);
      if (cnt >= n) {
        r = mid - 1;
      } else
        l = mid + 1;
    }

    if (cnt5(l) == n)
      cout << l;
    else
      cout << -1;
    cout << '\n';
  }
}
