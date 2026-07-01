// Source: https://codeforces.com/contest/1368/problem/B
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 01/07/2026 (DD/MM/YYYY).
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
ll k, freq[10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 10; ++i)
    freq[i] = 1;

  cin >> k;
  ll total = 1;
  while (true) {
    if (total >= k)
      break;
    for (int i = 0; i < 10; ++i) {
      total = total / freq[i] * (++freq[i]);

      if (total >= k)
        break;
    }
  }

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < freq[i]; ++j) {
      if (i == 0 || i == 7)
        cout << 'c';
      else if (i == 1 || i == 5)
        cout << 'o';
      else if (i == 2)
        cout << 'd';
      else if (i == 3 || i == 8)
        cout << 'e';
      else if (i == 4)
        cout << 'f';
      else if (i == 6)
        cout << 'r';
      else if (i == 9)
        cout << 's';
    }
  }
}
