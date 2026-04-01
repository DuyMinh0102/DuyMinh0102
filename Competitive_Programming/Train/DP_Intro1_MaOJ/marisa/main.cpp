#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long res = 0;

int main(){
    string s; cin >> s;

    long long dp[7] = {0};

    dp[0] = 1;
    for (char c : s){
        if (c == 'm') dp[1] = (dp[0] + dp[1]) % MOD;
        else if (c == 'a'){
            dp[6] = (dp[6] + dp[5]) % MOD;
            dp[2] = (dp[2] + dp[1]) % MOD;
        }
        else if (c == 'r') dp[3] = (dp[3] + dp[2]) % MOD;
        else if (c == 'i') dp[4] = (dp[4] + dp[3]) % MOD;
        else if (c == 's') dp[5] = (dp[5] + dp[4]) % MOD;
    }

    cout << dp[6];
}