#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll mx_diff = 0, cur_mx;

void solve() {
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cur_mx = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] < cur_mx)
      mx_diff = max(mx_diff, cur_mx - a[i]);

    else
      cur_mx = a[i];
  }

  int seconds = 0;
  while (mx_diff > 0) {
    mx_diff >>= 1;
    seconds++;
  }

  cout << seconds << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
