// Source: https://codeforces.com/contest/126/problem/B
// Status: Solved
/*
Note: Given a string S, find a substring that serves as the prefix, suffix and appears between the string it self.

Solution: KMP

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 17/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long

// Variables
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    ll n = s.length();

    if (n < 3){
        cout << "Just a legend";
        return 0;
    }

    vector<int> pi(n);
    for (int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    int mx = 0;
    for (int i = 1; i < n - 1; ++i) mx = max(mx, pi[i]);

    int res = pi[n - 1];
    while (res > 0 && res > mx) res = pi[res - 1];

    if (res == 0) cout << "Just a legend";
    else cout << s.substr(0, res);
}