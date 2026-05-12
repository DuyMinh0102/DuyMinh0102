// Source: https://codeforces.com/contest/546/problem/D
// Status: Unsolved
/*
Note:

Solution:

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
const int N = 5000005;

// Variables
int t, a, b;
ll sum[N], fact[N];
vector<int> p(N, 0);

void sang() {
  p[0] = p[1] = 1;
  for (int i = 2; i * i < N; ++i) {
    if (p[i] == 0) {
      for (int j = i * i; j < N; j += i) {
        if (p[j] == 0)
          p[j] = i;
      }
    }
  }

  for (int i = 2; i < N; ++i)
    if (p[i] == 0)
      p[i] = i;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  sang();

  for (int i = 2; i < N; ++i) {
    fact[i] = fact[i / p[i]] + 1;
    sum[i] = sum[i - 1] + fact[i];
  }

  cin >> t;

  while (t--) {
    cin >> a >> b;

    cout << (sum[a] - sum[b]) << '\n';
  }
}
