#include <bits/stdc++.h>
using namespace std;
#define dbg(desc, x) cerr << "DBG: " << desc << ' ' << x << '\n';
const int N = 2e5 + 5;
int t;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        string s; cin >> s;
        int n = s.size();

        int cnt = 0;

        for(int i = 0; i < n; ++i){
            if ((i == 0 || i == (n - 1)) && s[i] == 'u'){
                s[i] = 's';
                ++cnt;
            }
            if (i > 0 && s[i] == 'u' && s[i - 1] == 'u'){
                s[i] = 's';
                ++cnt;
            }
        }

        cout << cnt << '\n';
    }
}