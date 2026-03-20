#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105, MOD = 1e9 + 7;
int n, k;
ll dp[N][1005];
bool isprime[2005] = {false};
vector<int> prime;

void sang(){
    isprime[0] = isprime[1] = true;

    for (int i = 2; i * i <= 2000; ++i){
        if (!isprime[i]){
            for (int j = i * i; j <= 2000; j += i){
                isprime[j] = true;
            }
        }
    }

    for (int i = 2; i <= 2000; ++i){
        if (!isprime[i]){
            prime.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    sang();

    cin >> n >> k;

    for (int i = 0; i <= k; ++i) dp[1][i] = 1;

    for (int i = 2; i <= n; ++i){
        for (int j = 0; j <= k; ++j){
            for (int l : prime){
                if (l > j + k) break;
                if (l < j) continue;

                dp[i][j] = (dp[i][j] + dp[i - 1][l - j]) % MOD;
            }
        }
    }

    ll res = 0;
    for (int i = 0; i <= k; ++i) res = (res + dp[n][i]) % MOD;

    cout << res;
}