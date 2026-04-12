#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> a >> b >> c;

        if ((a + b + c) % 2 != 0){
            cout << "-1\n";
            continue;
        }

        int cnt = 0;
        while(a > 0 || b > 0){
            --c;
            --b;

            if (c < a) swap(a, c);
            else if (b < a) swap(a, b);

            ++cnt;
        }
        cout << cnt << '\n';
    }
}