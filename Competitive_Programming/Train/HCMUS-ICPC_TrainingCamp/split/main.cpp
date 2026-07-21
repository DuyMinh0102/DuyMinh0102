// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 21/07/2026 (DD/MM/YYYY).
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

// Variables
int n, k;
vector<int> S;
vector<vector<int>> ins;
vector<int> split;
vector<ll> cnt(35, 0);

void output(int v) {
  if (v > 0 && split[v] > 0) {
    --split[v];
    output(v - 1);
    output(v - 1);
  } else
    cout << v << ' ';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    S.pb(x);
  }

  ins.resize(n + 1);

  vector<int> st;
  ll curk = 0;

  for (int i = 0; i < n; ++i) {
    int x = S[i];

    while (!st.empty() && st.back() < x) {
      int v = st.back();

      ins[i].pb(v);
      ++curk;
      ++cnt[v];

      while (!st.empty() && st.back() == v) {
        st.pop_back();
        ++v;
      }
      st.pb(v);
    }

    while (!st.empty() && st.back() == x) {
      st.pop_back();
      ++x;
    }
    st.pb(x);
  }

  while (st.size() > 1 || (st.size() == 1 && st.back() < 30)) {
    int v = st.back();
    ins[n].pb(v);
    ++curk;
    ++cnt[v];

    while (!st.empty() && st.back() == v) {
      st.pop_back();
      ++v;
    }
    st.pb(v);
  }

  ll split_need = k - curk;
  split.assign(35, 0);

  for (int v = 30; v > 0; --v) {
    while (cnt[v] > 0 && split_need > 0) {
      --split_need;
      --cnt[v];
      ++split[v];
      cnt[v - 1] += 2;
    }
  }

  for (int i = 0; i <= n; ++i) {
    for (int v : ins[i])
      output(v);
    if (i < n)
      cout << S[i] << ' ';
  }
}
