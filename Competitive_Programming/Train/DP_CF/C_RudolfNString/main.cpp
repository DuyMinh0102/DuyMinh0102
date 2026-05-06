#include <bits/stdc++.h>
using namespace std;
int t, n;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        cin >> n;

        string s; cin >> s;

        int cnt = 0;

        int i = 0;
        while(i < n - 2){
            string t = s.substr(i, 3);
            string v = s.substr(i, 5);

            if (v == "mapie"){
                ++cnt;
                i += 4;
                continue;
            }
            else if (t == "map" || t == "pie"){
                ++cnt;
                i += 2;
                continue;
            }
            
            ++i;
        }

        cout << cnt << '\n';
    }
}