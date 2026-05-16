// Source: https://codeforces.com/contest/1360/problem/F
// Status: Unsolved
/*
Note:
The constraints for this problem are very small (n, m <= 10). This suggests that 
a brute-force approach is feasible. A "spy-string" must differ from the first 
string a[0] by at most one character. Therefore, we can generate all strings 
that differ from a[0] by exactly one position and check if any of them satisfy 
the condition for all other strings in the set.

Solution:
1. Take the first string a[0] as a base.
2. Iterate through every index i (0 to m-1) and every character c ('a' to 'z').
3. Create a candidate string by replacing a[0][i] with c.
4. For each candidate, check if it differs from every string a[j] by <= 1 position.
5. If a match is found, print it and move to the next test case.
6. If no candidate works after all iterations, print -1.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 15/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) \
  cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' \
       << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Function to check if the candidate matches the "at most one difference" rule
bool check(const string& candidate, int n, int m, const vector<string>& a) {
    for (int i = 0; i < n; ++i) {
        int diff = 0;
        for (int j = 0; j < m; ++j) {
            if (candidate[j] != a[i][j]) {
                diff++;
            }
        }
        if (diff > 1) return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    string candidate = a[0];
  
    for (int i = 0; i < m; ++i) {
        char originalChar = candidate[i];
        for (char c = 'a'; c <= 'z'; ++c) {
            candidate[i] = c;
            
            if (check(candidate, n, m, a)) {
                cout << candidate << "\n";
                return;
            }
        }
        candidate[i] = originalChar;
    }

    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
