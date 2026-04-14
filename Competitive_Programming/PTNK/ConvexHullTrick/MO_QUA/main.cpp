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