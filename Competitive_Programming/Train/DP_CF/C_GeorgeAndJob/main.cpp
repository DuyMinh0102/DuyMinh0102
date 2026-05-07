// Source: https://codeforces.com/contest/467/problem/C
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 04/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 5005;

// Variables
int n, m, k;
ll a[N], pref[N], segmentsum[N];
vector<ll> prevdp, currdp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = m; i <= n; ++i) segmentsum[i] = pref[i] - pref[i - m];

    currdp.resize(n + 1);
    prevdp.resize(n + 1);

    for (int i = 1; i <= k; ++i){
        fill(currdp.begin(), currdp.end(), 0);

        for (int j = i * m; j <= n; ++j){
            currdp[j] = max(currdp[j - 1], prevdp[j - m] + segmentsum[j]);
        }
        prevdp = currdp;
    }

    cout << prevdp[n];
}