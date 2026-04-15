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