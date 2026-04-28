// Source: https://codeforces.com/contest/295/problem/B
// Status: Solved
/*
Note: (pending)

Solution: (pending)

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 28/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 505;

// Variables
int n, p[N];
ll a[N][N], ans[N];
bool visited[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }

    for (int i = 1; i <= n; ++i) cin >> p[i];

    for (int t = n; t > 0; --t){
        int k = p[t];
        visited[k] = true;

        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }

        ll sum = 0;
        for (int i = 1; i <= n; ++i){
            if (visited[i]){
                for (int j = 1; j <= n; ++j){
                    if (visited[j]) sum += a[i][j];
                }
            }
        }

        ans[t] = sum;
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}