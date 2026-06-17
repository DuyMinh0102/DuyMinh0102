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
int n;
string s;
vector<int> pos[2];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("TG01BSTR.inp", "r", stdin);
  freopen("TG01BSTR.out", "w", stdout);

  cin >> n >> s;

  for (int i = 0; i < n; ++i) {
    int d = s[i] - '0';
    pos[d].pb(i);
  }

  int mxlen = 0, curlen = 0;
  string ans = "";
  for (int l = 1; l < pos[0].size(); ++l) {
    string cur = "";
    int ps = pos[0][l - 1], nxt_st[2];
    for (int i = 0; i < l; ++i)
      cur += '0';
    nxt_st[0] = l - 1;
    nxt_st[1] = 0;
    curlen = l;
    int nxt = 1;

    while (true) {
      auto id = upper_bound(pos[nxt].begin() + nxt_st[nxt], pos[nxt].end(), ps);
      if (id == pos[nxt].end()) {
        break;
      }

      if (nxt == 1) {
        ++curlen;
        nxt_st[1] = id - pos[1].begin();
        cur += '1';
        ps = pos[1][id - pos[1].begin()];
      } else {
        curlen += l;
        nxt_st[0] = id - pos[0].begin() + l;
        for (int i = 0; i < l; ++i)
          cur += '0';
        ps = pos[0][id - pos[0].begin()];
      }

      nxt ^= 1;
    }

    if (cur.back() == '1') {
      cur.pop_back();
      --curlen;
    }
    if (curlen > mxlen) {
      mxlen = curlen;
      ans = cur;
    }
  }

  cout << mxlen << '\n' << ans;
}
