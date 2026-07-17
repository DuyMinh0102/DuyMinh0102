// Source: https://codeforces.com/contest/1385/problem/D
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 16/07/2026 (DD/MM/YYYY).
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
const int INF = 200000;

// Variables
int t, n, logt;
string s;

int cnt(int l, int r, char c) {
  if (l > r)
    return 0;
  if ((r - l) == 2) {
    char nxt = (int)c + 1;

    return min((s[l] != c) + (s[r - 1] != nxt),
               (s[r - 1] != c) + (s[l] != nxt));
  }

  int mid = l + ((r - l) >> 1);
  int cnt_l = 0, cnt_r = 0;

  for (int i = l; i < mid; ++i) {
    cnt_l += (s[i] != c);
    cnt_r += (s[i + mid - l] != c);
  }

  char nxt = (int)(c) + 1;
  return min(cnt_l + cnt(mid, r, nxt), cnt_r + cnt(l, mid, nxt));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n >> s;
    logt = 0;

    if (n == 1) {
      cout << (s[0] != 'a') << '\n';
      continue;
    }

    int tmp = n;
    while (tmp) {
      ++logt;
      tmp >>= 1;
    }

    cout << cnt(0, n, 'a') << '\n';
  }
}
