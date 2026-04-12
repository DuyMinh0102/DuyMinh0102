#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, sz;
string n;

string sub[] = {"00", "25", "50", "75"};

int f(string n, string c){
    char first = c[0], second = c[1];

    int i = sz - 1;
    int cnt = 0;
    for (; i >= 0; --i){
        if (n[i] == second) break;
        ++cnt;
    }

    if (i < 0) return 20;
    if (i == 0 && n[i] != first) return 20;

    --i;
    for (; i >= 0; --i){
        if (n[i] == first) break;
        ++cnt;
    }

    if (i < 0) return 20;

    return cnt;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    cin >> t;

    while(t--){
        cin >> n;
        sz = n.size();

        string check = n.substr(n.size() - 2);

        if (check == "00" || check == "25" || check == "75" || check == "50") cout << 0 << '\n';
        else{
            int ans = 20;
            for (int i = 0; i < 4; ++i){
                ans = min(ans, f(n, sub[i]));
            }

            cout << ans << '\n';
        }
    }
}