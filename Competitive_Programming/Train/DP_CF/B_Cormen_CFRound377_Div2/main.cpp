// Source: https://codeforces.com/problemset/problem/732/B
// Status: Solved
/*
Note: Given two intergers n and k. For any two consecutive days, you have to walk the dog a total of k times.
You're given n intergers, how many times you'd walk the dog on the i-th day.
Output:
- First line: the amount of additional walks needed
- Second line: n intergers, the amount of times you'd walk the dog on the i-th day

Solution: A linear brute force, greedy style, starting from the second day
if (a[i] + a[i - 1] < k) a[i] = k - a[i - 1]

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 10/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, k, a[N];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int cnt = 0;

    for (int i = 1; i < n; ++i){
        int pre = a[i] + a[i - 1], org = a[i];
        if (pre < k) a[i] = k - a[i - 1];

        cnt += abs(a[i] - org);
    }

    cout << cnt << '\n';
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
}