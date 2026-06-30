// Source:
// Status:
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
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
int n;
vector<int> beauty;

bool prime(int x) {
  if (x < 2)
    return false;
  if (x < 4)
    return true;
  if (x % 2 == 0 || x % 3 == 0)
    return false;
  for (int i = 5; i * i <= x; i += 6) {
    if (min(x % i, x % (i + 2)) == 0)
      return false;
  }
  return true;
}

ll sumdig(int x) {
  ll sum = 0;
  while (x) {
    sum += (x % 10) * (x % 10);
    x /= 10;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 11; i <= 10000000; ++i) {
    ll cur = sumdig(i);
    if (prime(cur))
      beauty.pb(i);

    if (beauty.size() == 1000000) {
      break;
    }
  }

  while (cin >> n) {
    cout << beauty[n - 1] << '\n';
  }
}
