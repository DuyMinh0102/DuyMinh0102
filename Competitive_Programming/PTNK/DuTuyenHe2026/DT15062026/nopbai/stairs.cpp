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
int h, w;
vector<pair<int, int>> st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("stairs.inp", "r", stdin);
  freopen("stairs.out", "w", stdout);

  cin >> h >> w;

  vector<vector<bool>> a(h + 5, vector<bool>(w + 5, 0));
  vector<vector<int>> conone(h + 5, vector<int>(w + 5, 0));

  for (int i = 1; i <= h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) {
      a[i][j + 1] = (s[j] == '1');
    }
    int cur = 0;
    for (int j = w; j >= 1; --j) {
      if (a[i][j] == 1)
        ++cur;
      else
        cur = 0;

      conone[i][j] = cur;
    }
  }

  int mx = 0;
  for (int j = w; j >= 1; --j) {
    int cur_sum = 0;
    st.clear();

    for (int i = 1; i <= h; ++i) {
      int cnt = 1;
      while (!st.empty() && st.back().first > conone[i][j]) {
        cur_sum -= st.back().first * st.back().second;
        cnt += st.back().second;
        st.pop_back();
      }
      st.pb({conone[i][j], cnt});
      cur_sum += conone[i][j] * cnt;
      mx = max(mx, cur_sum);
    }
  }

  cout << mx;
}
