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
ll n;

ll lg2(ll x) {
  ll cnt = 0;
  while (x > 1) {
    x >>= 1;
    ++cnt;
  }
  return cnt;
}

void solve() {
  cin >> n;

  ll k = lg2(n + 1);
  ll s = (1LL << k) - 1;
  ll diff = n - s, x = 0;

  if (k > 0) {
    ll mask = (1LL << k) - 1;
    x = ((diff << 1) & mask) | (diff >> (k - 1));
  }

  ll par = 0;
  if (k > 1) {
    ll id = x >> 1, kp = k - 1, sp = (1LL << kp) - 1;

    ll offset = (id >> 1) | ((id & 1) << (kp - 1));
    par = sp + offset;
  }

  ll left = (1LL << (k + 1)) - 1 + x;
  ll right = left + (1LL << k);

  cout << par << '\n' << left << ' ' << right;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("paint.inp", "r", stdin);
  freopen("paint.out", "w", stdout);

  solve();
}
