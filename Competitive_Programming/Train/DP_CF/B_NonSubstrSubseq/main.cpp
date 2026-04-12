#include <bits/stdc++.h>
using namespace std;
#define dbg(desc, x) cerr << "DBG - " << desc << ' ' << x << '\n';
int t, n, q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while(t--){
        cin >> n >> q;

        string s; cin >> s;

        int lst[2] = {0}, fst[2] = {0};

        for (int i = 0; i < s.size(); ++i){
            int id = s[i] - '0';
            if (fst[id] == 0) fst[id] = i + 1;
            lst[id] = max(lst[id], i + 1);
        }
        
        while(q--){
            int l, r; cin >> l >> r;

            if (l != fst[s[l - 1] - '0'] || r != lst[s[r - 1] - '0']) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}