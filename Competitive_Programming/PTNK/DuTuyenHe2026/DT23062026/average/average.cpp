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
const int N = 100005;

// Variables
int n, k;
ll a[N], pref[N];
map<ll, int> m;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("average.inp", "r", stdin);
  freopen("average.out", "w", stdout);

  cin >> n >> k;

  pref[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i] - k;
  }

  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    if (m[pref[i]] == 0) {
      m[pref[i]] = i;
    } else
      mx = max(mx, i - m[pref[i]]);
  }

  cout << mx;
}
