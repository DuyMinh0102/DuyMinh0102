#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 205;
const ll MOD = 1e9 + 7;

// Variables
int n, k;
vector<int> b;
bool mat[N][7];
ll res = 0;

void solve(int id) {
  if (id > n) {
    res = (res + 1) % MOD;
    return;
  }

  for (int i = 0; i < (1 << k); ++i) {
    int cnt = 0;
    for (int j = 0; j < k; ++j) {
      if (i & (1 << j)) {
        mat[id][j] = true;
      } else
        mat[id][j] = false;
    }

    if (sum == b[id])
      solve(id + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("treasure.inp", "r", stdin);
  freopen("treasure.out", "w", stdout);

  cin >> n >> k;
  b.resize(n + 1);

  for (int i = 1; i <= n; ++i)
    cin >> b[i];

  solve(1);

  cout << res;
}
