#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<ll, ll> m;
int q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;

    while(q--){
        int t; cin >> t;

        if (t == 1){
            ll x, a; cin >> x >> a;

            m[x] += a;
        }
        else if (t == 2){
            ll x, b; cin >> x >> b;

            if (m.count(x)){
                m[x] -= b;

                if (m[x] <= 0) m.erase(x);
            }
        }
        else if (t == 3){
            if (!m.empty()) cout << (m.begin()->first) << '\n';
        }
        else if (t == 4){
            if (!m.empty()) cout << (m.rbegin()->first) << '\n';
        }
        else{
            ll y; cin >> y;
            ll cnt = 0;
            if (!m.empty()){

                auto it = m.lower_bound(y);
                if (m.count(y)){
                    if (it != m.end() && it->first == y) cnt += it->first*it->second;

                    if (it != m.begin()) cnt += prev(it)->first*prev(it)->second;

                    if (it != m.end()) cnt += next(it)->first*next(it)->second;
                }
                else{
                    cnt += it->first*it->second;

                    if (it != m.begin()) cnt += prev(it)->first*prev(it)->second;
                }
            }

            cout << cnt << '\n';
        }
    }
}