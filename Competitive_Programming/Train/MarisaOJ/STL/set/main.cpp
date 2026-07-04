#include <bits/stdc++.h>
using namespace std;
int q;
multiset<int> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;

    while(q--){
        int t, x; 
        cin >> t >> x;

        if (t == 1) s.insert(x);
        else if (t == 2){
            auto it = s.find(x);
            if (it != s.end()) s.erase(it);
        }
        else if (t == 3){
            auto it = s.upper_bound(x);
            if (it == s.end()) cout << -1 << '\n';
            else cout << *it << '\n';
        }
        else{
            auto it = s.upper_bound(x);
            
            if (it == s.begin()) cout << -1 << '\n';
            else{
                --it;
                cout << *it << '\n';
            }
        }
    }
}