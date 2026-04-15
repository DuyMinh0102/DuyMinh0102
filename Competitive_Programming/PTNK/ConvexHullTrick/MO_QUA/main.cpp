// Source: ptnkoj, Problems/moqua.png
// Status: Solved
/* 
Note: There are n gifts, indexed 1 to n, the i-th gift has a weight w_i.
You can open multiple gifts at the same time, but if you open gifts in a range [l, r],
the cost will be (sum(w_i) for i in range [l, r])^2 + C,
where C is a constant given in the input.
Minimize the cost.

Solution:
let dp[i] be the minimum cost to open the first i gifts,
we can either: open the i-th gift alone, or open it together with the previous gifts.
we will now denote w_i as the sum of the first i weights.
Then dp[i] = min(dp[j] + (w_i - w_j)^2 + C) for all j < i and i in range [1, n].
Then, dp[i] will be w_i^2 + C - 2.w_i.w_j + w_j^2 + dp[j].
We have a constant: w_i^2 + C.
The remaining part is a linear function of w_i: (-2.w_j).w_i + (w_j^2 + dp[j]).
We see that the slope is -2.w_j, b is w_j^2 + dp[j].
We can use a convex hull trick and a deque to maintain the lines and query the minimum value

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 14/04/2026
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int N = 1e5 + 5;
int n;
ll c, dp[N], w[N];

struct line{
    ll m, b;
    ll val(ll x){ return m * x + b; }
};
deque<line> dq;

bool is_bad(line l1, line l2, line l3){
    return (db)(l2.b - l1.b) * (l2.m - l3.m) >= (db)(l3.b - l2.b) * (l1.m - l2.m);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n >> c;

    for (int i = 1; i <= n; ++i){
        cin >> w[i];
        w[i] += w[i - 1];
    }

    dq.push_back({0, 0});
    for (int i = 1; i <= n; ++i){
        while(dq.size() >= 2 && dq[0].val(w[i]) >= dq[1].val(w[i])) dq.pop_front();

        dp[i] = dq[0].val(w[i]) + w[i]*w[i] + c;

        line newline = {-2 * w[i], dp[i] + w[i] * w[i]};
        while(dq.size() >= 2 && is_bad(dq[dq.size()- 2], dq.back(), newline)) dq.pop_back();

        dq.push_back(newline);
    }

    cout << dp[n];
}