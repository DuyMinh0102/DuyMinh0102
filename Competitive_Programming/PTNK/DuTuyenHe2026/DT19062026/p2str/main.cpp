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
#define ll long long

const int N = 5005;

bool isPal[N][N];
int prefStart[N][N], prefEnd[N][N];
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;
  int n = s.length();

  string str = " " + s;

  for (int len = 1; len <= n; ++len) {
    for (int i = 1; i + len - 1 <= n; ++i) {
      int j = i + len - 1;
      if (len == 1) {
        isPal[i][j] = true;
      } else if (len == 2) {
        isPal[i][j] = (str[i] == str[j]);
      } else {
        isPal[i][j] = (str[i] == str[j] && isPal[i + 1][j - 1]);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = i; j <= n; ++j) {
      if (isPal[i][j])
        ++cnt;
      prefStart[i][j] = cnt;
    }
  }

  for (int j = 1; j <= n; ++j) {
    int cnt = 0;
    for (int i = j; i >= 1; --i) {
      if (isPal[i][j])
        ++cnt;
      prefEnd[i][j] = cnt;
    }
  }

  ll ans = 0;

  for (int S = 2; S <= 2 * n; ++S) {
    int match_len = 0;
    for (int u = 1; u <= S - 1; ++u) {
      int v = S - u;
      if (v > n)
        continue;
      if (u >= v)
        break;

      if (str[u] == str[v]) {
        ++match_len;
      } else {
        match_len = 0;
      }

      if (match_len > 0) {

        ans += match_len;

        if (u <= v - 2) {

          ans += (ll)match_len * prefStart[u + 1][v - 1];

          ans += (ll)match_len * prefEnd[u + 1][v - 1];
        }
      }
    }
  }

  cout << ans << "\n";
}
