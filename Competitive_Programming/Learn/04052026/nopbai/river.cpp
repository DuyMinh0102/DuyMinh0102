#include <bits/stdc++.h>
using namespace std;

#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

#define pb push_back
#define ll long long
const int MOD = 1e9 + 7;

ll power(ll x, ll y) {
  ll res = 1;
  x %= MOD;
  while (y > 0) {
    if (y % 2 == 1)
      res = (res * x) % MOD;
    x = (x * x) % MOD;
    y /= 2;
  }
  return res;
}

ll inv[505];
ll f[505];
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("river.inp", "r", stdin);
  freopen("river.out", "w", stdout);

  cin >> n;

  vector<int> a(n), b(n);
  vector<int> coords;

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    coords.pb(a[i]);
    coords.pb(b[i] + 1);
  }

  sort(coords.begin(), coords.end());
  coords.erase(unique(coords.begin(), coords.end()), coords.end());

  for (int i = 1; i <= n; ++i)
    inv[i] = power(i, MOD - 2);

  f[0] = 1;

  for (int k = 0; k < coords.size() - 1; ++k) {
    int L = coords[k + 1] - coords[k];

    for (int i = n; i >= 1; --i) {
      if (!(a[i - 1] <= coords[k] && b[i - 1] >= coords[k + 1] - 1))
        continue;

      int cnt = 0;
      ll comb = 1;

      for (int p = i - 1; p >= 0; --p) {
        int j = p + 1;

        if (a[j - 1] <= coords[k] && b[j - 1] >= coords[k + 1] - 1) {
          ++cnt;
          comb = (comb * (L + cnt - 1)) % MOD;
          comb = (comb * inv[cnt]) % MOD;
        }

        if (f[p] > 0) {
          f[i] = (f[i] + f[p] * comb) % MOD;
        }
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = (ans + f[i]) % MOD;

  cout << ans;

  return 0;
}
