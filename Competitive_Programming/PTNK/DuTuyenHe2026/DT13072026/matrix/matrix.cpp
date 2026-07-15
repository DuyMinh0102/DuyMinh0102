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
const int MXVAL = 1000005;

// Variables
int n;
int mp[MXVAL], a[N];

void sang() {
  mp[0] = mp[1] = 1;

  for (ll i = 2; i < MXVAL; ++i) {
    if (mp[i] == 0) {
      mp[i] = i;
      for (ll j = i * i; j < MXVAL; j += i)
        if (mp[j] == 0)
          mp[j] = i;
    }
  }
}

void sub134() {
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 2 || a[i] == 3)
      cout << 1 << ' ';
    else
      cout << 2 << ' ';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("matrix.inp", "r", stdin);
  freopen("matrix.out", "w", stdout);

  sang();

  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }

  if (mx <= 4) {
    sub134();
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    while (a[i] > 1) {
      a[i] /= mp[a[i]];
      ++cnt;
    }

    if (cnt & 1)
      cout << 1 << ' ';
    else
      cout << 2 << ' ';
  }
}
