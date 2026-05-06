// Source: https://codeforces.com/problemset/problem/1900/B
// Status: Solved
/*
Note: Given three intergers a, b, and c. Each represents as the frequency of the numbers 1, 2 and 3.
You can choose two different digits, erase them, then write another that is different from the two chosen.
For each query, answer if you can erase the digits to somehow left only 1s, 2s, or 3s on the board.

Solution: Greedy.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 08/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        cin >> a >> b >> c;

        cout << ((b - c) % 2 == 0) << ' ' << ((a - c) % 2 == 0) << ' ' << ((a - b) % 2 == 0) << '\n';
    }
}