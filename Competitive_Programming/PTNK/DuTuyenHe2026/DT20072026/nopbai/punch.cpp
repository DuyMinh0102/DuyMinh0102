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
struct CharPos {
  int p;
  char c;
};
int n, m;
string s;

vector<vector<CharPos>> card;
vector<int> bad, ans;
vector<vector<int>> bad_card;
vector<bool> mark, flex;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("punch.inp", "r", stdin);
  freopen("punch.out", "w", stdout);

  cin >> n >> m >> s;
  s = ' ' + s;

  card.resize(n + 1);
  bad.resize(n + 1, 0);
  bad_card.resize(m + 1);
  mark.resize(m + 1, false);
  flex.resize(m + 1, false);

  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;

    for (int j = 0; j < k; ++j) {
      int p;
      char c;
      cin >> p >> c;
      card[i].pb({p, c});
      mark[p] = true;

      if (s[p] != c) {
        ++bad[i];
        bad_card[p].pb(i);
      }
    }
  }

  for (int i = 1; i <= m; ++i)
    if (!mark[i]) {
      cout << -1;
      return 0;
    }

  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (bad[i] == 0)
      q.push(i);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    ans.pb(u);

    for (const CharPos &i : card[u]) {
      int p = i.p;
      if (!flex[p]) {
        flex[p] = true;

        for (int v : bad_card[p]) {
          --bad[v];
          if (bad[v] == 0)
            q.push(v);
        }
      }
    }
  }

  if ((int)ans.size() == n) {
    for (int i = 0; i < n; ++i)
      cout << ans[i] << ' ';
  } else
    cout << -1;
}
