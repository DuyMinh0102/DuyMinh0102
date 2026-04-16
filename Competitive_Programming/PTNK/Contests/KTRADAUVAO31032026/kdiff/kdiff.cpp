#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long cnt = 0;
int n, k, freq[N], a[N], distinct = 0;
bool valid = false;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("kdiff.inp", "r", stdin); freopen("kdiff.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int l = 1, r = 0;
    while(r < n){
        while(!valid && r < n){
            ++freq[++r];
            if (freq[r] == 1) ++distinct;

            if (distinct == k) valid = true;
            else valid = false;
        }
        while(valid && l < r){
            ++cnt;
            --freq[l];
            if (freq[l] == 0) --distinct;
            ++l;

            if (distinct == k) valid = true;
            else valid = false;
        }
    }

    cout << cnt;
}