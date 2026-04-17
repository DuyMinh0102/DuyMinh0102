// Source: https://codeforces.com/problemset/problem/1501/b
// Status: Solved
/*
Note: Nothing important to note. Read the problem by the link provided.

Solution: a backward brute force with a temporary variable
Time complexity O(N).

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 07/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, a[N];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<bool> c(n + 1, false);

        int cream = 0;
        for (int i = n; i > 0; --i){
            if (a[i] > cream) cream = a[i];

            if (cream > 0){
                --cream;
                c[i] = 1;
            }
        }

        for (int i = 1; i <= n; ++i) cout << c[i] << ' ';

        cout << '\n';
    }
}