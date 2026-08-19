// Source: https://codeforces.com/problemset/problem/166/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 19/08/2026 (DD/MM/YYYY).
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
const ll MOD = 1000000007;

// Variables
int n;
struct matrix {
  ll mat[2][2];

  matrix() { mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1]; }

  matrix operator*(const matrix &other) const {
    matrix ans;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          ans.mat[i][j] += (ans.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
}
