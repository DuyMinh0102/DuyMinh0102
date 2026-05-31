// Source: https://marisaoj.com/problem/145
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 30/05/2026 (DD/MM/YYYY).
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
const int N = 1e5 + 5;

// Variables
int n, m;
vector<int> a;
bool f[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  a.resize(m);
  for (int i = 0; i < m; ++i)
    cin >> a[i];
  sort(a.begin(), a.end());

  f[0] = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i - a[j] < 0)
        break;

      if (!f[i - a[j]])
        f[i] = true;
    }
  }

  if (f[n])
    cout << "Marisa";
  else
    cout << "Reimu";
}
