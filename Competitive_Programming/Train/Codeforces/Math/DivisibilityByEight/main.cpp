// Source: https://codeforces.com/contest/550/problem/C
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/07/2026 (DD/MM/YYYY).
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
string n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int l = n.size();

  for (int i = 0; i < l; ++i) {
    int num = n[i] - '0';
    if (num % 8 == 0) {
      cout << "YES\n" << num;
      return 0;
    }
  }

  for (int i = 0; i < l; ++i)
    for (int j = i + 1; j < l; ++j) {
      int num = (n[i] - '0') * 10 + n[j] - '0';
      if (num % 8 == 0) {
        cout << "YES\n" << num;
        return 0;
      }
    }

  for (int i = 0; i < l; ++i)
    for (int j = i + 1; j < l; ++j)
      for (int k = j + 1; k < l; ++k) {
        int num = (n[i] - '0') * 100 + (n[j] - '0') * 10 + (n[k] - '0');
        if (num % 8 == 0) {
          cout << "YES\n" << num;
          return 0;
        }
      }

  cout << "NO";
}
