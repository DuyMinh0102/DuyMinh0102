// Source: https://codeforces.com/contest/1036/problem/C
// Status: Solved
/*
Note: Count the amount of numbers within [L; R] that there decimal
representation has no more than 3 non-zero digits.

Solution: Presenting every number as a 19-digit number (so 500 will be
represented as 0000000000000000500), we can pick 3 out of those 19 spots to fill
in any number from 1 to 9. So it's 3C19*729 where 729 is the amount of 3 digit
combo we can make from 1 to 9, which means we can precompute everything and
binary search on them later.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 18/05/2026 (DD/MM/YYYY).
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
int t;
ll l, r;
vector<ll> nums;

void gen(int pos, int nonzerocnt, ll val) {
  if (pos == 18) {
    nums.pb(val);
    return;
  }

  gen(pos + 1, nonzerocnt, val * 10);

  if (nonzerocnt < 3) {
    for (ll i = 1; i < 10; ++i) {
      gen(pos + 1, nonzerocnt + 1, val * 10 + i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  gen(0, 0, 0);

  nums.pb(1000000000000000000LL);
  sort(nums.begin(), nums.end());

  cin >> t;
  while (t--) {
    cin >> l >> r;

    auto it_l = lower_bound(nums.begin(), nums.end(), l);

    auto it_r = upper_bound(nums.begin(), nums.end(), r);

    cout << distance(it_l, it_r) << '\n';
  }
}
