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
const int N = 1000005;

// Variables
int n;
ll a[N], l[N], r[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  ll curmx;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];

    if (i == 1) {
      curmx = a[i];
      l[i] = a[i];
    } else {
      curmx = max(a[i], curmx + a[i]);
      l[i] = max(l[i - 1], curmx);
    }
  }

  curmx = a[n];
  r[n] = a[n];

  for (int i = n - 1; i >= 1; --i) {
    curmx = max(a[i], curmx + a[i]);
    r[i] = max(r[i + 1], curmx);
  }

  ll mx = l[1] + r[2];

  for (int i = 1; i < n; ++i)
    mx = max(mx, l[i] + r[i + 1]);

  cout << mx;
}
