// Source: https://codeforces.com/contest/2128/problem/D
// Status: Solved
/*
Note: A game where you first place a white rook on (r, c) then the computer
places a black rook at (c, r). No two rooks should see each other (i.e. on the
same col or row). There will be k played moves given, determine how many
configurations can be made before the game ends.

Solution: Because of the symmetry, when you place a rook, it eithers:
- Occupies one whole row and one whole column (r == c)
- Occupies two rows and two column (r != c)
So we create an occupied[] list where occupied[i] simply answers if i-th row and
i-th column is occupied or not.
If we place the next rook at (r, c) where r == c:
We have m - 1 places left to place it (where m is the amount of valid row-column
places left) If we place the next rook at (r, c) where r != c We have m - 2
places left to place (since the computer mimics our action and place one more
rook at (c, r)) But because you place a white rook, the computer places a black
rook so choosing (r, c) or (c, r) on your turn creates two different
configurations So we have 2 x (m - 1) ways to choose. The amonnt of ways to
choose left is f(m - 2).

So: f(m) = f(m - 1) + 2*(m - 1)*f(m - 2)

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 22/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ": " << debugDescription << " "   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 300005;
const ll MOD = 1000000007;

// Variables
int t, n, k;
ll f[N];

void solve() {
  cin >> n >> k;

  int used = 0;
  for (int i = 1; i <= k; ++i) {
    int r, c;
    cin >> r >> c;

    ++used;
    if (r != c)
      ++used;
  }

  cout << f[n - used];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  f[0] = f[1] = 1;
  for (int i = 2; i < N; ++i) {
    f[i] = (f[i - 1] + 2 * (i - 1) * f[i - 2]) % MOD;
  }

  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
}
