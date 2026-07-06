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
int n, a[N];
vector<ll> L(N, 1), R(N, 1);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("bitonic.inp", "r", stdin);
  freopen("bitonic.out", "w", stdout);

  cin >> n;

  for (int i = 1; i <= n; ++i)
    cin >> a[i];

  for (int i = 2; i <= n; ++i)
    if (a[i] > a[i - 1])
      L[i] = L[i - 1] + 1;

  for (int i = n - 1; i > 0; --i)
    if (a[i] > a[i + 1])
      R[i] = R[i + 1] + 1;

  ll total = 0;
  for (int i = 1; i <= n; ++i)
    total += L[i] * R[i];

  cout << total;
}
