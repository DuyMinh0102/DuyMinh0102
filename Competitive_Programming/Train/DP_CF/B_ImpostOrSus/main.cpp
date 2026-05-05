// Source: https://codeforces.com/problemset/problem/2178/B
// Status: Solved
/*
Note: Given a string S. Change some characters so that for every character 'u', 
the closest character 's' on the left and right have the same distance relative to the current 'u' considering.

Solution: Greedy, there's nothing more I can say about this problem.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 09/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
#define dbg(desc, x) cerr << "DBG: " << desc << ' ' << x << '\n';
const int N = 2e5 + 5;
int t;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        string s; cin >> s;
        int n = s.size();

        int cnt = 0;

        for(int i = 0; i < n; ++i){
            if ((i == 0 || i == (n - 1)) && s[i] == 'u'){
                s[i] = 's';
                ++cnt;
            }
            if (i > 0 && s[i] == 'u' && s[i - 1] == 'u'){
                s[i] = 's';
                ++cnt;
            }
        }

        cout << cnt << '\n';
    }
}