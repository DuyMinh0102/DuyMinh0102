// Source: https://codeforces.com/contest/1632/problem/C
// Status: Solved
/*
Note: two number a, b. You can either increase a by 1, increase b by 1, or make a = a | b (| is bitwise or operation)
Find the minimum number of steps so a = b

Solution: We brute force through possible values of a (from a -> b - 1)
We want it so that we can OR a into some value B (B >= b)
In other words balancing between increasing a, b and OR-ing them.
If for a value a in [a; b), it's i-th bit is 1 -> B must have a 1 at there too 
If _______________________, ________________ 0 -> We should put a 0 there for B (except if B is not yet >= b)
To make it easier, we iterate from the most important bit position to the least important

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 10/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Variables
int a, b, t;

void solve(){
  cin >> a >> b;
  
  int mn = b - a;
  for (int i = a; i < b; ++i){
    int tmp = 0;
    bool greater = false;

    for (int j = 21; j >= 0; --j){
      int bit_a = (i >> j) & 1, bit_b = (b >> j) & 1;

      if (bit_a == 1){
        tmp |= (1 << j);
        if (bit_b == 0) greater = true;
      }
      else{
        if (!greater && bit_b == 1){
          tmp |=  (1 << j);
        }
      }
    }

    mn = min(mn, i - a + tmp - b + 1);
  }

  cout << mn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t; 
    while(t--){
      solve();
      cout << '\n';
    }
}
