#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 100005;

// Variables
int n, q, mx = 0, cnt_o = 0;
int pref[N], suf[N], ans[N];
vector<int> iso, queries;
string s;

void solve() {
  cin >> n >> q >> s;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      ++cnt_o;
    if (s[i] == '1' && (i == 0 || s[i - 1] == '0') &&
        (i == n - 1 || s[i + 1] == '0'))
      iso.push_back(i);
  }

  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    queries.push_back(x);
  }

  if (cnt_o == 0) {
    for (int k : queries) {
      cout << (k > 1 ? min(k, n) : 0) << '\n';
    }
    return;
  }

  int m = 0;
  for (int i = 0, c = 1; i < (int)iso.size(); i++) {
    if (i + 1 < (int)iso.size() && iso[i + 1] - iso[i] == 2)
      c++;
    else {
      m += c / 2;
      c = 1;
    }
  }

  int w = n - cnt_o;
  int t3 = m, t2 = iso.size() - 2 * m, t1 = max(0, w - t3 - t2);
  int q0 = cnt_o - iso.size();

  for (int target_k : queries) {
    int k = min(target_k, w);

    int u3 = min(k, t3);
    k -= u3;

    int u2 = min(k, t2);
    k -= u2;

    int u1 = min(k, t1);

    cout << q0 + 3 * u3 + 2 * u2 + u1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("repose.inp", "r", stdin);
  freopen("repose.out", "w", stdout);

  solve();
}
