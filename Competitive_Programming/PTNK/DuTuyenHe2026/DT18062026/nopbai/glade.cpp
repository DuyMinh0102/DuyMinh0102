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
const ll MOD = 1e9 + 9, B = 9973;

// Variables
int m, n;
vector<ll> bpow, p_hash(2 * N, 0);
ll hashS = 0;

ll getHash(int st, int en) {
  ll val = p_hash[en + 1] - ((p_hash[st] * bpow[en - st + 1]) % MOD);
  return (val % MOD + MOD) % MOD;
}

void solve() {
  hashS = 0;

  cin >> n;

  string s = "";
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    s += (char)(x + '0');
  }

  string t = s;
  reverse(t.begin(), t.end());
  t += t;

  for (int i = 0; i < s.size(); ++i) {
    hashS = ((hashS * B) % MOD + s[i]) % MOD;
  }

  p_hash[0] = 0;
  for (int i = 0; i < t.size(); ++i) {
    p_hash[i + 1] = ((p_hash[i] * B) % MOD + t[i]) % MOD;
  }

  int lens = s.size(), lent = t.size();

  for (int i = lens; i <= lent; ++i) {
    if (getHash(i - lens, i - 1) == hashS) {
      cout << "Yes";
      return;
    }
  }

  cout << "No";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("glade.inp", "r", stdin);
  freopen("glade.out", "w", stdout);

  bpow.pb(1);
  while (bpow.size() <= 200005)
    bpow.pb((bpow.back() * B) % MOD);

  cin >> m;
  while (m--) {
    solve();
    cout << '\n';
  }
}
