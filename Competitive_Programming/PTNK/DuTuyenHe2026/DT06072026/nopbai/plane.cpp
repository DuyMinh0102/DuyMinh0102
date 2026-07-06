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
int n, m, cnt_empty = 0;
bool seat[1005][11];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("plane.inp", "r", stdin);
  freopen("plane.out", "w", stdout);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      char c;
      cin >> c;
      seat[i][j] = (c == 'X');

      if (!seat[i][j])
        ++cnt_empty;
    }
  }

  if (m > cnt_empty) {
    cout << "Impossible";
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      if (seat[i][j] && !seat[i][6 - j + 1]) {
        if (m == 0) {
          cout << "Impossible";
          return 0;
        }
        seat[i][6 - j + 1] = true;
        --m;
      }
    }
  }

  if (m & 1) {
    cout << "Impossible";
    return 0;
  }

  for (int i = 1; i <= n && m > 0; ++i) {
    for (int j = 1; j <= 3 && m > 0; ++j) {
      if (!seat[i][j]) {
        m -= 2;
        seat[i][j] = seat[i][6 - j + 1] = true;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j)
      cout << (seat[i][j] ? 'X' : '.');
    cout << '\n';
  }
}
