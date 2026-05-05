#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        cin >> n;

        string s; cin >> s;

        if (n == 1){
            cout << "0\n";
            continue;
        }

        int cnt = 0, st = -1;
        bool flip = false;
        for (int i = 0; i < n; ++i){
            if (s[i] == '1'){
                st = i;
                break;
            }
        }

        if (st == -1){
            cout << "0\n";
            continue;
        }

        for (int i = st + 1; i < n; ++i){
            int cur = (s[i] - '0') ^ flip;

            if (cur == 0){
                ++cnt;
                flip = flip ^ 1;
            }
        }

        cout << cnt << '\n';
    }
}