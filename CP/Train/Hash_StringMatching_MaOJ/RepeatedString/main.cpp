#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s;

    int n = s.size();
    int p[n] = {0};

    for (int i = 1; i < n; ++i){
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }

    int k = n - p[n - 1];
    cout << s.substr(0, k);
}