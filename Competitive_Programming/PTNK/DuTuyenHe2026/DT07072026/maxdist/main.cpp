// Source:
// Status: Solved
/*
Note:

Solution:

author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/07/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

#define dbg(testingLine, debugDescription, testedVariable)                     \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' '   \
       << testedVariable << '\n';

#define pb push_back
#define ll long long
#define ull unsigned long long
ll n, L, R;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> L >> R;

  vector<ll> A(n);
  for (int i = 0; i < n; ++i)
    cin >> A[i];

  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  n = A.size();

  vector<ll> candidates;
  candidates.push_back(L);
  candidates.push_back(R);

  for (int i = 0; i < n - 1; ++i) {
    ll a = A[i], b = A[i + 1];

    ull diff = (ull)b - (ull)a;

    ll mid1 = a + (ll)(diff / 2), mid2 = a + (ll)((diff + 1) / 2);

    if (mid1 >= L && mid1 <= R)
      candidates.push_back(mid1);
    if (mid2 >= L && mid2 <= R)
      candidates.push_back(mid2);
  }

  ll res = L;
  ull mx_dist = 0;
  bool first = true;
  for (ll x : candidates) {
    auto it = lower_bound(A.begin(), A.end(), x);
    ull cur_dist = 0;

    if (it == A.end())
      cur_dist = (ull)x - (ull)A.back();
    else if (it == A.begin())
      cur_dist = (ull)A.front() - (ull)x;
    else {
      ull d1 = (ull)x - (ull) * (it - 1), d2 = (ull)*it - (ull)x;
      cur_dist = min(d1, d2);
    }

    if (first || cur_dist > mx_dist || (cur_dist == mx_dist && x > res)) {
      mx_dist = cur_dist;
      res = x;
      first = false;
    }
  }

  cout << res << "\n";
}
