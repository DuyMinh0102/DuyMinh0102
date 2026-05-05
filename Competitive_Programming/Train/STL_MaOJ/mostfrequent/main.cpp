#include <bits/stdc++.h>
#define ll long long
using namespace std;
int q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> q;
    map<ll, ll> counts;

    set<pair<ll, ll>> best;

    while (q--){
        int t;
        cin >> t;
        
        if (t == 1){
            ll x, a;
            cin >> x >> a;
            
            ll c = counts[x];
            if (c > 0) best.erase({c, x});
            
            counts[x] = c + a;
            best.insert({counts[x], x});
            
        } else if (t == 2){
            ll x, b;
            cin >> x >> b;
            
            ll c = counts[x];
            if (c > 0){
                best.erase({c, x});
                ll new_c = c - b;
                
                if (new_c > 0){
                    counts[x] = new_c;
                    best.insert({new_c, x});
                } 
                else counts.erase(x);
            }
            
        } 
        else{
            if (!best.empty()) cout << best.rbegin()->second << "\n";
        }
    }
    return 0;
}