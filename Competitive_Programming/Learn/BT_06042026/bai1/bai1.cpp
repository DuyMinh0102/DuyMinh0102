#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5;
int n;
ll lst, k = 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("bai1.inp", "r", stdin); freopen("bai1.out", "w", stdout);

    cin >> n;

    int cnt = 0;
    while(cnt < n){
        ll multi = lst / k + 1;
        
        for (int i = 0; i < k; ++i){
            ++cnt;
            lst = multi * k;
            ++multi;

            if (cnt == n) break;
        }
        ++k;
    }

    cout << lst;
}