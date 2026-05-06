// Source: Problems/BT_20260226.pdf
// Status: Solved.
/*
Note: Given an array of n intergers and an interger k.
Task: Remove k intergers from the array.
Let M be the greatest difference between any two intergers left
Let m be the smallest difference between any two intergers left
Find the minimum possible value of M + m.

Solution: Sliding window + something to solve the query of minimum difference/maximum difference within a range
Basically Sliding window + RMQ.
Time complexity: O(n log n), if use ST another O(n log n). 

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 26/02/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int n, k, a[N];
ll t[4*N];

void build(int k, int l, int r){
    if (l == r){
        t[k] = a[l + 1] - a[l];
        return;
    }

    int m = (l + r) >> 1;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
    t[k] = min(t[k << 1], t[k << 1 | 1]);
}

ll query(int k, int l, int r, int tl, int tr){
    if (l > tr || r < tl) return 1e9;
    if (tl <= l && r <= tr) return t[k];

    int m = (l + r) >> 1;
    return min(query(k << 1, l, m, tl, tr), query(k << 1 | 1, m + 1, r, tl, tr));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("minmm.inp", "r", stdin);
    freopen("minmm.out", "w", stdout);

    cin >> n >> k;

    if (n - k < 2){
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);
    build(1, 1, n - 1);

    int window = n - k;
    ll res = LLONG_MAX;
    for (int i = 1; i <= k + 1; ++i){
        int r = i + window - 1;
        ll m = query(1, 1, n - 1, i, r - 1);
        ll M = a[r] - a[i];
        res = min(res, M + m);
    }

    cout << res;
}