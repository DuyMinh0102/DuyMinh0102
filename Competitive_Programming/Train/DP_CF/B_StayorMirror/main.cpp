// Source: https://codeforces.com/contest/2129/problem/B
// Status: Unsolved
/*
Note: ..

Solution: ..

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 16/05/2026.
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
int n, t;

void solve() {
  ll min_inver = 0;

  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  for (int k = 0; k < n; k++) {
    int A_k = 0;
    for (int i = 0; i < k; i++) {
      if (p[i] > p[k]) {
        A_k++;
      }
    }
    int B_k = 0;
    for (int j = k + 1; j < n; j++) {
      if (p[k] < p[j]) {
        B_k++;
      }
    }
    min_inver += min(A_k, B_k);
  }
  cout << min_inver << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}
