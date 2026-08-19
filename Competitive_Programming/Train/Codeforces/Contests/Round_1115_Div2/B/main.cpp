// Source: https://codeforces.com/contest/2252/problem/B
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

    string s;
    cin >> s;

    deque<char> compressed_s;
    int total_0 = 0, total_1 = 0, left_0 = 0, left_1 = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0')
        ++total_0;
      else
        ++total_1;

      if (s[i] != s[i - 1] || i == 0) {
        compressed_s.push_back(s[i]);
        if (s[i] == '0')
          ++left_0;
        else
          ++left_1;
      }
    }

    int need_del_0 = total_0 - left_0, need_del_1 = total_1 - left_1;

    int diff = need_del_0 - need_del_1;
    if (abs(diff) > 3)
      cout << -1;
    else if (abs(diff) > 1) {
      if (diff < 0) {
        int need = need_del_1 - need_del_0;

        if (need == 3)
          cout << ((compressed_s[0] == '0' && compressed_s.back() == '0')
                       ? need_del_1 + need_del_0 + 2
                       : -1);
        if (need == 2)
          cout << ((compressed_s[0] == '0' || compressed_s.back() == '0')
                       ? need_del_1 + need_del_0 + 1
                       : -1);
      } else {
        int need = need_del_0 - need_del_1;

        if (need == 3)
          cout << ((compressed_s[0] == '1' && compressed_s.back() == '1')
                       ? need_del_1 + need_del_0 + 2
                       : -1);
        if (need == 2)
          cout << ((compressed_s[0] == '1' || compressed_s.back() == '1')
                       ? need_del_1 + need_del_0 + 1
                       : -1);
      }
    } else
      cout << need_del_0 + need_del_1;

    cout << '\n';
  }
}
