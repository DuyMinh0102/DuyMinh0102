// Source: https://codeforces.com/contest/1516/problem/C
// Status: Solved
/*
Note: If an array can be partitioned into two different subsequence so that their sum is equal,
find the minimum number of operations (delete) to make it impossible.

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 09/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 105;

// Variables
int n, a[N];
vector<bool> dp(200005, false);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i){
      cin >> a[i];
      sum += a[i];
    }

    if (sum & 1){
      cout << 0;
      return 0;
    }

    int target = sum / 2;
    dp[0] = true;
    for (int i = 1; i <= n; ++i){
      for (int j = target; j >= a[i]; --j){
        if (dp[j - a[i]]) dp[j] = true;
      }
    }

    if (!dp[target]){
      cout << 0;
      return 0;
    }

    int mn_zero = 32, best = -1;

    for (int i = 1; i <= n; ++i){
      int cur_zero = __builtin_ctz(a[i]);
      if (cur_zero < mn_zero){
        mn_zero = cur_zero;
        best = i;
      }
    }

    cout << 1 << '\n' << best;
}
