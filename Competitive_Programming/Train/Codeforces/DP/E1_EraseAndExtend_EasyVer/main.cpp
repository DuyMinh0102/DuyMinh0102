// Source: https://codeforces.com/contest/1537/problem/E1 and https://codeforces.com/contest/1537/problem/E2
// Status: Solved
/*
Note: Find the most optimal prefix of the original string

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long

// Variables
int n, k;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> s;

    int len = 1;
    for (int i = 1; i < n; ++i){
        if (s[i] > s[i % len]) break;
        else if (s[i] < s[i % len]) len = i + 1;
    }

    for (int i = 0; i < k; ++i) cout << s[i % len];
}