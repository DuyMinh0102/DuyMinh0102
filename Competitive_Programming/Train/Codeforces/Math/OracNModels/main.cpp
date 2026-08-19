#include <bits/stdc++.h>
using namespace std;
int n, t;

void solve() {
  cin >> n;

  vector<int> s(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> s[i];

  vector<int> dp(n + 1, 1);
  int mx = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = i * 2; j <= n; j += i) {
      if (s[i] < s[j])
        dp[j] = max(dp[j], dp[i] + 1);
    }

    mx = max(mx, dp[i]);
  }

  cout << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--)
    solve();

  return 0;
}
