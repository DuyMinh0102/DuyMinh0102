#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 5005;

// Variables
int n, a[N], b[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("median.inp", "r", stdin);
  freopen("median.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b + 1, b + n + 1);

  int median = b[(n + 1) / 2];

  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    int less = 0, eq = 0;

    for (int j = i; j <= n; ++j) {
      if (a[j] < median)
        ++less;
      else if (a[j] == median)
        ++eq;

      int l = j - i + 1, req = (l + 1) / 2;

      if (less < req && (less + eq) >= req)
        ++res;
    }
  }

  cout << res;
}
