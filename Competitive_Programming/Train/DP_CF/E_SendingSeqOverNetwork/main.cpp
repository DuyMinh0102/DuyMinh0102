// Source: https://codeforces.com/contest/1741/problem/E
// Status: Solved
/*
Note: Given a sequence of numbers B. Determine if you can re-crypt it into segments that has it's length written on the left or the right of it.

Solution: We check two cases:
- If B[i] is the length indicator on the right of a segment:
    Then dp[i - b[i] - 1] must be true (also i - b[i] - 1 >= 0) => dp[i] = true;
- If B[i] is the length indicator on the left of a segment:
    Then dp[i - 1] must be true and so dp[i + b[i]] is true

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 27/04/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define pb push_back
#define ll long long
const int N = 2e5 + 5;

// Variables
int t, n;
int b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while(t--){
        cin >> n;
        bool dp[n + 1];
        for (int i = 1; i <= n; ++i){
            cin >> b[i];
            dp[i] = false;
        }

        dp[0] = true;

        for (int i = 1; i <= n; ++i){
            if (i + b[i] <= n && dp[i - 1]) dp[i + b[i]] = true;

            if (i - b[i] - 1 >= 0){
                if (dp[i - b[i] - 1]){
                    dp[i] = true;
                }
            }
        }

        if (dp[n]) cout << "YES\n";
        else cout << "NO\n";
    }
}