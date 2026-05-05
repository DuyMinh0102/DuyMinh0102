// Source: Problems/solved/abinlis.jpg
// Status: Solved
/* 
Note: Find the longest common non decreasing subsequence of two array A and B.
Solution: we can test every possible amount of 0s from 1 to min(zero in A, zero in B), 
the rest is determined by (1 to the right of i in A, 1 to the right of i in B). 
We can precompute the suffix sum of 1s to get the answer in O(1) time. The complexity is O(n + m).

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 30/03/2026
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int m, n, a[N], b[N];
int suf_a[N], suf_b[N];
vector<int> pre_a, pre_b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("abinlis.inp", "r", stdin); freopen("abinlis.out", "w", stdout);

    cin >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
        if (a[i] == 0) pre_a.push_back(i);
    } 
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        if (b[i] == 0) pre_b.push_back(i);
    }

    suf_a[m + 1] = suf_b[n + 1] = 0;
    for (int i = m; i >= 1; --i) suf_a[i] = suf_a[i + 1] + (a[i] == 1);
    for (int i = n; i >= 1; --i) suf_b[i] = suf_b[i + 1] + (b[i] == 1);

    int mx = 0, k = min(pre_a.size(), pre_b.size());

    for (int i = 0; i <= k; ++i){
        int len = i, id_a = (i == 0) ? 0 : pre_a[i - 1], id_b = (i == 0) ? 0 : pre_b[i - 1];

        len += min(suf_a[id_a + 1], suf_b[id_b + 1]);

        mx = max(mx, len);
    }   

    cout << mx;
}