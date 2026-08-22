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
ll n;
struct matrix {
  ll mat[2][2];

  matrix() { mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 0; }

  void dv() { mat[0][0] = mat[1][1] = 1; }

  matrix operator*(const matrix &other) const {
    matrix ans;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k)
          ans.mat[i][k] = (ans.mat[i][k] + mat[i][j] * other.mat[j][k]) % MOD;

    return ans;
  }
};

matrix binpow(matrix a, ll p) {
  matrix res;
  res.dv();

  while (p > 0) {
    if (p & 1)
      res = res * a;
    a = a * a;
    p >>= 1;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  matrix T;
  T.mat[0][0] = 0;
  T.mat[0][1] = 3;
  T.mat[1][0] = 1;
  T.mat[1][1] = 2;

  matrix Tn = binpow(T, n);

  cout << Tn.mat[0][0];
}
