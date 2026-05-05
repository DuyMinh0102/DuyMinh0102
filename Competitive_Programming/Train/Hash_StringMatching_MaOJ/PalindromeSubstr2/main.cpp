#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll pi[N] = {0}, c = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string t; cin >> t;
    string s = "@";
    for (char c : t){
        s += "#";
        s += c;
    }
    s += "#$";
    int n = s.size();

    ll l = 0, r = 0, res = 0;

    for (int i = 1; i < n; ++i){
        int mir = l + r - i;

        if (i < r) pi[i] = min(r - i, pi[mir]);

        while(s[i + 1 + pi[i]] == s[i - 1 - pi[i]]) ++pi[i];

        if (pi[i] + i > r){
            l = i - pi[i];
            r = i + pi[i];
        }

        res += (pi[i] + 1) / 2;
    }

    cout << res;
}