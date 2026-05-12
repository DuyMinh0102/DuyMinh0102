// Source: https://codeforces.com/contest/165/problem/C/
// Status: Solved
/*
Note: Given a binary string (consists only of 0s and 1s), count the number of
substrings that has exactly k 1s.

Solution: There are two main cases:
k = 0 -> We then count the amount of substrings that has a 0 in it. O(N)
k != 0:
- Let dp[i] be the amout of 1s that appear from 0 to i.
- Let cnt[i] be the amount of times the value of dp[i] occurs within the dp
array itself.
- Iterate through the cnt array from k -> the amuont of 1s appear throughout the
whole array. We have some stuff to note here:
- The amount of time a value i appears within the dp array is the amount of ways
to end a substr there.
- For a substr to end in one of those value i, it must start from a position
with a total of (i - k) 1s from 0 to i - k. So there will be exactly k 1s within
that substr So, the amount of substr that can end at any i is cnt[i] * cnt[i -
k] Which is basically: amount_of_starting_pos * amount_of_ending_pos.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 12/05/2026 (DD/MM/YYYY).
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
const int N = 1e6 + 5;

// Variables
int k;
string s;
ll dp[N], cnt[N], res = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k >> s;

  int n = s.size();
  ll len = 0;

  if (k == 0) {
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        ++len;
      } else {
        res += (len * (len + 1)) / 2;
        len = 0;
      }
    }

    if (len != 0)
      res += (len * (len + 1)) / 2;
  } else {
    ll lim = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == '1')
        ++len;
      cnt[len]++;
      lim = max(lim, len);
    }

    for (int i = k; i <= lim; ++i) {
      res += cnt[i] * cnt[i - k];
    }
  }

  cout << res;
}
