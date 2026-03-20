#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
vector<int> a, pref, base;
ll sum[32] = {0LL};
map<vector<int>, int> freq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("funbit.inp", "r", stdin); freopen("funbit.out", "w", stdout);

    cin >> n >> k;

    if (k == 1){
        cout << n;
        return 0;
    }

    a.resize(n + 1);
    pref.resize(k, 0);
    base.resize(max(1, k - 1), 0);
    freq[base] = 0;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    int len = 0;    

    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < k; ++j){
            if ((a[i] >> j) & 1) ++pref[j];
        }

        vector<int> cur_state;
        for (int j = 1; j < k; ++j) cur_state.push_back(pref[j] - pref[0]);

        if (freq.count(cur_state)) len = max(len, i - freq[cur_state]);
        else freq[cur_state] = i;
    }

    cout << len;    
}