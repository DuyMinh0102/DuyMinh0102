#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int t; cin >> t;

    while(t--){
        cin >> a >> b >> c;

        cout << ((b - c) % 2 == 0) << ' ' << ((a - c) % 2 == 0) << ' ' << ((a - b) % 2 == 0) << '\n';
    }
}