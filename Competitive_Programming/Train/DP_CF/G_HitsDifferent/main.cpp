// Source: https://codeforces.com/contest/1829/problem/G
// Status: Pending
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Variables
int t;
ll n;
vector<ll> dp[1505];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int l = 1; l <= 1500; ++l){
        for (int i = 1; i <= l; ++i){
            dp[l].push_back((i + l - 1)*(i + l - 1));
        }
    }

    cin >> t;

    while(t--){
        
    }
}