// Source: https://codeforces.com/problemset/problem/1709/B
// Status: Solved
/*
Note: Given N columns and M quests. If the next column you go to is lower than the current, take some damage equal to the difference.
Else, no damage.
Determine the total damage taken for each quest.
each quest you are given two int l and r.
l can be greater than r, meaning going backwards

Solution: A two way prefix
if l > r, use the backward prefix, else the forward prefix.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 08/04/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5, INF = 2e9;
ll n, m, a[N], pre_dif[N], suf_dif[N];

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    pre_dif[0] = suf_dif[n + 1] = 0;
    for (int i = 1; i < n; ++i) pre_dif[i] = max(0LL, a[i] - a[i + 1]) + pre_dif[i - 1];

    for (int i = n; i > 1; --i) suf_dif[i] = max(0LL, a[i] - a[i - 1]) + suf_dif[i + 1];

    for (int i = 0; i < m; ++i){
        int l, r; cin >> l >> r;

        if (l > r) cout << (suf_dif[r + 1] - suf_dif[l + 1]) << '\n';
        else cout << (pre_dif[r - 1] - pre_dif[l - 1]) << '\n';   
    }
}