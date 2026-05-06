// Source: No source
// Status: Solved
/*
Note: Find the longest common prefix shared by any two distinct strings from N strings

Solution: Sort -> Calculate LCP for each pair of neighbors.
Time complexity O(N.L) where L is the length of the string.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 16/04/2026
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long

// Variables
int n;
vector<string> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; ++i){
        string s; cin >> s;
        st.push_back(s);
    }
    sort(st.begin(), st.end());

    int mx = 0;
    for (int i = 0; i < n - 1; ++i){
        int cur = 0, len = min(st[i].size(), st[i + 1].size());
        for (int j = 0; j < len; ++j){
            if (st[i][j] == st[i + 1][j]) ++cur;
            else break;
        }
        mx = max(cur, mx);
    }

    cout << mx;
}