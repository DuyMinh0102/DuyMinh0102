#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 200005;

// Variables
ll n, m, lg2_m = 0, mx_t = 0;
ll a[N], t[N];

ll binpow(ll x, ll y) {
  if (y >= 62)
    return m + 1;

  return 1LL << y;
}

ll calc(ll time) {
  ll val = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > time)
      continue;

    ll cur;
    if (a[i] + t[i] > time)
      cur = 0;
    else
      cur = time - t[i] - a[i] + 1;

    val += binpow(2LL, cur);

    if (val > m)
      return val;
  }

  return val;
}

void input() {
  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    mx_t = max(mx_t, t[i] + a[i]);
  }

  int tmp = m;
  while (tmp) {
    tmp /= 2;
    ++lg2_m;
  }
}

void solve() {
  ll l = 1, r = mx_t + lg2_m, ans = r;
  while (l <= r) {
    ll mid = l + ((r - l) >> 1);

    ll cur_val = calc(mid);
    if (cur_val >= m) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  if (calc(ans) != m)
    cout << -1;
  else
    cout << ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("bacteria.inp", "r", stdin);
  freopen("bacteria.out", "w", stdout);

  input();

  solve();

  return 0;
}
