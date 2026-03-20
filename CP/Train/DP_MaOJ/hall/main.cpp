#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n;
vector<int> t[N + 5];
long long dp[N + 5] = {0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    
    for (int i = 1; i <= n; ++i){
        int l, r; cin >> l >> r;
        t[r].push_back(l);
    }

    dp[0] = 0;
    for (int i = 1; i <= N; ++i){
        dp[i] = dp[i - 1];
        for (int l : t[i]){
            dp[i] = max(dp[i], dp[l - 1] + i - l + 1);
        }
    }

    cout << dp[N];
}