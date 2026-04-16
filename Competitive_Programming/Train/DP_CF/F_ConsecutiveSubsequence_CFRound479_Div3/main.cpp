// Source: https://codeforces.com/contest/977/problem/F
// Status: Solved
/*
Note: Find the longest subsequence of the array that consists of consecutive intergers.
Output the maximum length k and the 1 based indices of each element in the subsequence.

Solution: DP, using a map dp[v] stores the maximum length of a subsequence that ends with the value v.
dp[v] = dp[v - 1] + 1. Then iterate -> find max -> output.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 16/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long

// Variables
const int N = 2e5 + 5;
map<int, int> dp;
int a[N], n;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n;

    int mxlen = 0, lst_val = 0;

    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (dp[a[i]] > mxlen){
            mxlen = dp[a[i]];
            lst_val = a[i];
        }
    }

    cout << mxlen << '\n';

    vector<int> res;
    ll cur = lst_val - mxlen + 1;

    for (int i = 1; i <= n; ++i){
        if (a[i] == cur){
            res.push_back(i);
            ++cur;
        }
    }

    for (int i : res) cout << i << ' ';
}