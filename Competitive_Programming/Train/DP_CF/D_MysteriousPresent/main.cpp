// Source: https://codeforces.com/contest/4/problem/D
// Status: Solved
/*
Note: given N envelopes, each has a width (w) and heght (h) where 1 <= w, h <=
10^6. A chain is a sequence of envelopes so that the ith envelope w and h is
strictly greater than the (i - 1)th envelope. Find the longest chain obtainable.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 31/05/2026 (DD/MM/YYYY).
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
const int N = 5005;

// Variables
int n, w, h;
struct env {
  int w, h, id;
  env() {}
  bool operator<(const env &other) {
    if (w != other.w)
      return w < other.w;

    return h < other.h;
  }
};
vector<env> a;
pair<int, int> dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> w >> h;
  env tmp;
  tmp.w = tmp.h = tmp.id = 0;
  a.pb(tmp);

  for (int i = 1; i <= n; ++i) {
    cin >> tmp.w >> tmp.h;
    if (tmp.w > w && tmp.h > h) {
      tmp.id = i;
      a.pb(tmp);
    }
  }

  if (a.size() == 1) {
    cout << 0;
    return 0;
  }
  n = a.size() - 1;

  sort(a.begin() + 1, a.begin() + n + 1);

  for (int i = 1; i <= n; ++i)
    dp[i] = {1, 0};

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (a[j].w < a[i].w && a[j].h < a[i].h) {
        if (dp[j].first + 1 > dp[i].first) {
          dp[i].first = dp[j].first + 1;
          dp[i].second = j;
        }
      }
    }
  }

  int mx_id = 0, mx = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i].first > mx) {
      mx = dp[i].first;
      mx_id = i;
    }
  }

  cout << mx << '\n';
  deque<int> o;
  while (mx_id != 0) {
    o.push_front(a[mx_id].id);
    mx_id = dp[mx_id].second;
  }

  for (int i : o)
    cout << i << ' ';
}
