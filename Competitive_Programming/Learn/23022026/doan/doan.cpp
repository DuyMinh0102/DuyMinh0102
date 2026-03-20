#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
struct seg{
    int l, r;
    bool operator < (seg& other){
        int lena = r - l + 1, lenb = other.r - other.l;
        if (lena != lenb) return lena < lenb;

        return l < other.l;
    }
};
vector<seg> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("doan.inp", "r", stdin);
    freopen("doan.out", "w", stdout);

    cin >> n;
    vector<int> val(N, 1);

    for (int i = 0; i < n; ++i){
        int l, r; cin >> l >> r;

        s.push_back({l, r});
    }

    sort(s.begin(), s.end());
    
    for (int i = 0; i < n; ++i){
        int id = i, len = 0;

        while(id < )
    }
}