#include <bits/stdc++.h>
using namespace std;
string s;
int q;
bool dp[2005][2005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> q;

    int n = s.size();

    for (int i = 1; i <= n; ++i) dp[i][i] = true;

    for (int i = 1; i < n; ++i){
        if (s[i] == s[i - 1]) dp[i][i + 1] = true;
    }

    for (int l = 3; l <= n; ++l){
        for (int i = 1; i <= n - l + 1; ++i){
            int j = i + l - 1;

            if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1]) dp[i][j] = true;
        }
    }

    while(q--){
        int l, r; cin >> l >> r;

        if (dp[l][r]) cout << "YES\n";
        else cout << "NO\n";
    }
}