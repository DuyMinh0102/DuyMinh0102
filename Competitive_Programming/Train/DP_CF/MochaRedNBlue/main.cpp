#include <bits/stdc++.h>
using namespace std;
int t, n;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        cin >> n;
        string s; int check = 0;
        cin >> s;

        for (int i = 0; i < n; ++i) check += (s[i] != '?');

        if (!check) s[0] = 'R';

        for (int i = 1; i < n; ++i){
            if (s[i] == '?' && s[i - 1] != '?'){
                s[i] = s[i - 1] ^ 'R' ^ 'B';
            }
        }

        for (int i = n; i >= 0; --i){
            if (s[i] == '?' && s[i + 1] != '?'){
                s[i] = s[i + 1] ^ 'R' ^ 'B';
            }
        }

        cout << s << '\n';
    }
}