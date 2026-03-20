#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll p = 31, m = 1e9 + 7, N = 1e6 + 5;
string t, s;
ll hashS[N], power[N], res = 0;

ll getHash(int i, int j){
    return (hashS[j] - hashS[i - 1] * power[j - i + 1] + m*m) %m;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> t;
    int lens = s.size(), lent = t.size();
    s = " " + s;
    t = " " + t;
    
    power[0] = 1;
    
    hashS[0] = 0;
    for (int i = 1; i <= lens; ++i){
        power[i] = (power[i - 1] * p) % m;
        hashS[i] = (hashS[i - 1] * p + s[i] - 'a' + 1) % m;
    }

    ll valT = 0;
    for (int i = 1; i <= lent; ++i){    
        valT = (valT*p + (t[i] - 'a' + 1)) % m;
    }

    ll res = 0;
    for(int i = 1; i <= lens - lent + 1; ++i){
        if (valT == getHash(i, i + lent - 1)) ++res;
    }

    cout << res;
}