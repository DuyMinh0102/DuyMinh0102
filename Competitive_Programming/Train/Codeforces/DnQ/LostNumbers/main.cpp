// Source: https://codeforces.com/contest/1167/problem/B
// Status: Unsolved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 16/07/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {4, 8, 15, 16, 23, 42};

struct quer {
  int a, b;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  map<int, quer> m;
  for (int i = 0; i < 6; ++i) {
    for (int j = i + 1; j < 6; ++j) {
      m[arr[i] * arr[j]] = {arr[i], arr[j]};
    }
  }

  vector<int> prod(4);
  for (int i = 0; i < 4; ++i) {
    cout << "? " << i + 1 << " " << i + 2 << "\n";
    cout << flush;
    cin >> prod[i];
  }

  quer q0 = m[prod[0]];
  quer q1 = m[prod[1]];

  int a2;
  if (q0.a == q1.a || q0.a == q1.b) {
    a2 = q0.a;
  } else {
    a2 = q0.b;
  }

  int a1 = prod[0] / a2;
  int a3 = prod[1] / a2;
  int a4 = prod[2] / a3;
  int a5 = prod[3] / a4;

  vector<int> ans = {a1, a2, a3, a4, a5};

  map<int, bool> used;
  for (int x : ans) {
    used[x] = true;
  }

  int a6 = -1;
  for (int x : arr) {
    if (!used[x]) {
      a6 = x;
      break;
    }
  }
  ans.push_back(a6);

  cout << "! ";
  for (int i = 0; i < 6; ++i) {
    cout << ans[i] << (i == 5 ? "" : " ");
  }
  cout << "\n";
  cout << flush;

  return 0;
}
