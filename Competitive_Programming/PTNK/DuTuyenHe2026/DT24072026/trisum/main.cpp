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
const ll MOD = 1e9 + 7;
const int N = 100005;

// Variables
struct item {
  ll val;
  int id;
};
item a[N], tempa[N];
ll L[N], pref[N];
int n;

void compute_l(int l, int r) {
  if (l >= r)
    return;

  int mid = l + ((r - l) >> 1);

  compute_l(l, mid);
  compute_l(mid + 1, r);

  pref[0] = 0;
  for (int i = l; i <= mid; ++i)
    pref[i - l + 1] = pref[i - l] + a[i].val;

  int p = l;
  for (int i = mid + 1; i <= r; ++i) {
    while (p <= mid && a[p].val <= a[i].val)
      ++p;

    ll c1 = p - l, c2 = mid - p + 1;
    ll s1 = pref[c1], s2 = pref[mid - l + 1] - pref[c1];

    ll val = a[i].val;

    L[a[i].id] += (c1 * val - s1) + (s2 - c2 * val);
  }

  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r) {
    if (a[i].val <= a[j].val)
      tempa[k++] = a[i++];
    else
      tempa[k++] = a[j++];
  }
  while (i <= mid)
    tempa[k++] = a[i++];
  while (j <= r)
    tempa[k++] = a[j++];

  for (int id = 0; id < k; ++id)
    a[l + id] = tempa[id];
}

void reset_n_compute(const vector<ll> &arr, vector<ll> &res) {
  for (int i = 0; i < n; ++i) {
    a[i] = {arr[i], i};
    L[i] = 0;
  }

  compute_l(0, n - 1);

  for (int i = 0; i < n; ++i)
    res[i] = L[i];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  vector<ll> inp(n), l_res(n), rev_a, r_res(n), rev_l_res(n);

  for (ll &i : inp)
    cin >> i;

  reset_n_compute(inp, l_res);

  rev_a = inp;
  reverse(rev_a.begin(), rev_a.end());

  reset_n_compute(rev_a, rev_l_res);

  for (int i = 0; i < n; ++i)
    r_res[i] = rev_l_res[n - i - 1];

  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    ll left = l_res[i] % MOD;
    ll right = r_res[i] % MOD;

    ans = (ans + left * right) % MOD;
  }

  cout << ans;
}
