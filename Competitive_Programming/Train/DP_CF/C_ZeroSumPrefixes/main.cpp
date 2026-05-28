// Source: https://codeforces.com/contest/1748/problem/C
// Status: Unsolved
/*
Note: A score of an array is the amount of indices i within the range [1; n] so
that the sum from the first element to i = 0. You can change any element as long
as it's 0 to any other number. Determine maximum score achieveable

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

// Variables
int t, n;
ll a[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  if (cin >> t) {
    while (t--) {
      cin >> n;
      for (int i = 1; i <= n; ++i) {
        cin >> a[i];
      }

      ll sum = 0;
      bool zero = false;
      vector<ll> block_sums;
      ll ans = 0;

      for (int i = 1; i <= n; ++i) {
        sum += a[i];

        if (a[i] == 0) {
          if (zero) {
            sort(block_sums.begin(), block_sums.end());
            int max_freq = 0, current_freq = 0;
            for (size_t j = 0; j < block_sums.size(); ++j) {
              if (j == 0 || block_sums[j] == block_sums[j - 1]) {
                current_freq++;
              } else {
                current_freq = 1;
              }
              max_freq = max(max_freq, current_freq);
            }
            ans += max_freq;
          } else {
            int zeros = 0;
            for (ll v : block_sums) {
              if (v == 0)
                zeros++;
            }
            ans += zeros;
          }
          zero = true;
          block_sums.clear();
        }
        block_sums.pb(sum);
      }

      if (zero) {
        sort(block_sums.begin(), block_sums.end());
        int max_freq = 0, current_freq = 0;
        for (size_t j = 0; j < block_sums.size(); ++j) {
          if (j == 0 || block_sums[j] == block_sums[j - 1]) {
            current_freq++;
          } else {
            current_freq = 1;
          }
          max_freq = max(max_freq, current_freq);
        }
        ans += max_freq;
      } else {
        int zeros = 0;
        for (ll v : block_sums) {
          if (v == 0)
            zeros++;
        }
        ans += zeros;
      }

      cout << ans << '\n';
    }
  }
  return 0;
}
