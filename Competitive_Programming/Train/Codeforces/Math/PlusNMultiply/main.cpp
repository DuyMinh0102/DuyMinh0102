#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t, n, a, b;

void solve() {
  cin >> n >> a >> b;

  if (a == 1) {
    if ((n - 1) % b == 0) {
      cout << "Yes\n";
      return;
    }

    cout << "No\n";
    return;
  }

  ll powa = 1;
  while (powa <= n) {
    if ((n - powa) % b == 0) {
      cout << "Yes\n";
      return;
    }

    powa *= a;
  }

  cout << "No\n";
}

int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
