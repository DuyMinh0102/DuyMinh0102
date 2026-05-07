// Source: https://codeforces.com/contest/1395/problem/C
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying atx High School for the Gifted, VNU - HCM.
Date: 07/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 
#define vt vector

// Config
#define pb push_back
#define ll long long
const int N = 205;
const ll INF = 1e18;

// Variables
int n, m;
ll a[N], b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    for (int t = 0; t <= 511; ++t){
        bool possible = true;

        for (int i = 1; i <= n; ++i){
            bool found = false;
            for (int j = 1; j <= m; ++j){
                if (((a[i] & b[j]) | t) == t){
                    found = true;
                    break;
                }
            }

            if (!found){
                possible = false;
                break;
            }
        }

        if (possible){
            cout << t;
            break;
        }
    }
}