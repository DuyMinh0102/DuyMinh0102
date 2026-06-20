#include <bits/stdc++.h>

using namespace std;

void Init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

long long nho[20][11];
vector<int> d;

long long dp(int idx, int lower, int last) {

  if (idx < 0)
    return (last != 10);

  if (!lower && nho[idx][last] != -1)
    return nho[idx][last];

  int cc = lower ? d[idx] : 9;
  long long ans = 0;

  if (last == 10)
    ans += dp(idx - 1, 0, 10);

  for (int i = 0; i <= cc; i++) {
    if (last == 10 && i == 0)
      continue;

    if (i == last)
      continue;

    ans += dp(idx - 1, lower && (i == cc), i);
  }

  if (!lower)
    nho[idx][last] = ans;

  return ans;
}

long long xuly(long long n) {
  if (n <= 0)
    return 0;

  d.clear();
  int len = 0;
  while (n > 0) {
    ++len;
    d.push_back(n % 10);
    n /= 10;
  }

  return dp(len - 1, 1, 10);
}

void Input() {
  long long l, r;
  cout << xuly(r) - xuly(l - 1) << '\n';
}

int main() {
  Init();

  memset(nho, -1, sizeof(nho));

  int t;
  while (t--)
    Input();
  return 0;
}
