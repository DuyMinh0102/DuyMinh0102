// Source: https://codeforces.com/contest/2252/problem/A
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/08/2026 (DD/MM/YYYY).
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while (t--) {
    cin >> n;

    map<int, int> freq;
    int mx_freq = 0, mx_freq_val = 0;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;

      sum += a;
      freq[a]++;

      if (freq[a] > mx_freq) {
        mx_freq = freq[a];
        mx_freq_val = a;
      }
    }

    int waste = max(0, 2 * mx_freq - n - 2);

    sum -= mx_freq_val * waste;

    cout << sum << '\n';
  }
}
