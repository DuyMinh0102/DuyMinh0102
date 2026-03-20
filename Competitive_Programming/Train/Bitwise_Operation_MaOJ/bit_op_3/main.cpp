#include <bits/stdc++.h>
using namespace std;
const int lg = 31;
int q, a = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;

    while(q--){
        int t; cin >> t;

        if (t == 1){
            int x; cin >> x;

            a ^= x;
        }
        else if (t == 2){
            if (a == 0) continue;
            for (int i = lg - 1; i >= 0; --i){
                if ((a >> i) & 1){
                    a &= ~(1 << i);
                    break;
                }
            }
        }
        else{
            int cnt = 0;
            for (int i = 0; i < lg; ++i) if ((a >> i) & 1) ++cnt;
            cout << cnt << '\n';
        }
    }
}