// Source: https://codeforces.com/problemset/problem/1973/A
// Status: Solved
/*
Note: T testcases. Given points of three friends. You get 0 for losing, 1 for drawing and 2 for winning.
Count the maximum amount of draws that could've happen. Or -1 if the scores are impossible to achieve.

Solution: The code is pretty simple so you should be able to figure it out by yourself.
if sum is not divisble by 2 => impossible to achieve.
Then just greedy the way through and get the result.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 08/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> a >> b >> c;

        if ((a + b + c) % 2 != 0){
            cout << "-1\n";
            continue;
        }

        int cnt = 0;
        while(a > 0 || b > 0){
            --c;
            --b;

            if (c < a) swap(a, c);
            else if (b < a) swap(a, b);

            ++cnt;
        }
        cout << cnt << '\n';
    }
}