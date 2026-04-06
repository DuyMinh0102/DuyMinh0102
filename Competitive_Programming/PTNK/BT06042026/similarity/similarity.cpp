#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
string s;
int z[N] = {0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("similarity.inp", "r", stdin);
    freopen("similarity.out", "w", stdout);

    cin >> s;
    int n = s.size();

    ll sum = 0;

    for (int i = 1, l = 0, r = 0; i < n; ++i){
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);

        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];

        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }

        sum += z[i];
    }

    cout << sum + n;
}
