#include <bits/stdc++.h>
#define c_bit(x, i) ((x >> i) & 1)
using namespace std;
const int lg = 15;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q; cin >> q;

    while(q--){
        int a, b; cin >> a >> b;

        int x = 0;

        for (int i = 0; i < lg; ++i){
            if (i < 5) x |= ((c_bit(a, i) ^ c_bit(b, i)) << i);
            else if (i < 10) x |= ((c_bit(a, i) & c_bit(b, i)) << i);
            else x |= ((c_bit(a, i) | c_bit(b, i)) << i);
        }

        cout << x << '\n';
    }
}