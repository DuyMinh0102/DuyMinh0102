// Source: https://codeforces.com/contest/547/problem/E
// Status: Solved
/*
Note:

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 23/07/2026 (DD/MM/YYYY).
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
const int N = 400005;

// Variables
int n, q;
struct node {
  int sum, lc, rc;
} t[20 * N];
int sa[N], rank[N], tmp[N], lcp[N];
int st[19][N], lg2[N];

void build_sa()

    int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
