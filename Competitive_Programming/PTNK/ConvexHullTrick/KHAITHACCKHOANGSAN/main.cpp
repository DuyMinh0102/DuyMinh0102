// Source: ptnkoj, Problems/ktqs.png
// Status: Solved
/* 
Note: There are n mines indexed from 1 to n.
The i-th mine has a quantity of s_i.
Problem: Divide these mines into several groups. If a group starts from the l-th mine and ends at the r-th mine,
the total quantity of this group is S = sum(s_i) for i in [l, r].
The output is calculated using the formula: a.S^2 + b.S + c,
a, b, care constants given in the input.

let dp[i] be the maximum output for the first i mines,
we can either: starts a new group, or add the i-th mine to the previous group.
Then dp[i] = dp[j] + a(S_i - S_j)^2 + b(S_i - S_j) + c, for all j < i and i in range [1, n].
Then, dp[i] will be a.S_i^2 + 2.a.S_i.S_j + a.S_j^2 + b.S_i - b.S_j + c + dp[j].
We have a constant: a.S_i^2 + b.S_i + c.
The remaining part is a linear function of S_i: (2.a.S_j).S_i + (a.S_j^2 - b.S_j + dp[j]).
We see that the slope is 2.a.S_j, b is a.S_j^2 - b.S_j + dp[j].
We can use a convex hull trick and a deque to maintain the lines and query the maximum value for each S_i.

Time complexity: O(n)

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 14/04/2026
*/

#include <bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int N = 1e6 + 5;
int n, a, b, c;
ll s[N], dp[N];
struct line{
    ll m, b;
    ll val(ll x){ return m * x + b;}
};
deque<line> dq;

bool is_bad(line l1, line l2, line l3){
    return (db)(l2.b - l1.b) * (l2.m - l3.m) >= (db)(l3.b - l2.b) * (l1.m - l2.m);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> n >> a >> b >> c;

    s[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> s[i];
        s[i] += s[i - 1];
    }

    dq.push_back({0, 0});
    for (int i = 1; i <= n; ++i){
        while(dq.size() >= 2 && dq[0].val(s[i]) >= dq[1].val(s[i])) dq.pop_front();

        dp[i] = s[i]*(a*s[i] + b) + c - dq[0].val(s[i]);

        line newline = {2*a*s[i], s[i]*(-a*s[i] + b) - dp[i]};
        while(dq.size() >= 2 && is_bad(dq[dq.size() - 2], dq.back(), newline)) dq.pop_back();

        dq.push_back(newline);
    }

    cout << dp[n];
}