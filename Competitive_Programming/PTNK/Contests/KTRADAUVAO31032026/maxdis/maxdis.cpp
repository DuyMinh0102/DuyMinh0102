// Source: ..
// Status: Unsolved
/*
Note: ..

Solution: ..

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 31/03/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5, MINVAL = -2e18;
ll n, L, R, a[N], mx_diff = 0, mx_val = MINVAL;

bool in_range(ll x){ return (x >= L && x <= R);}

ll mndiff(ll x){ return (min(abs(x - L), abs(x - R)));}

ll calc(ll x, ll id){
    if (in_range(x)) return min(x - a[id], a[id + 1] - x);
    else return mndiff(x);
}

void is_max(ll x, ll d){
    if (d >=mx_diff){
        mx_diff = d;
        mx_val = x;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("maxdis.inp", "r", stdin); freopen("maxdis.out", "w", stdout);

    cin >> n >> L >> R;
    for (int i = 1; i <= n; ++i)  cin >> a[i];

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i){
        if (!in_range(a[i])){
            ll d;
            if (a[i] < L) d = L - a[i];
            if (a[i] > R) d = a[i] - R;

            is_max(a[i], d);
        }

        if (a[i] == a[i + 1] - 1) continue;
        else{
            if ((a[i + 1] - a[i]) % 2 == 0){
                ll mid = a[i] + (a[i + 1] - a[i]) / 2, curdiff;
                curdiff = calc(mid, i);

                is_max(mid, curdiff);
            }
            else{
                ll mid_1 = a[i] + (a[i + 1] - a[i]) / 2, mid_2 = mid_1 + 1, diff_1, diff_2;

                diff_1 = calc(mid_1, i);
                diff_2 = calc(mid_2, i);

                is_max(mid_1, diff_1);
                is_max(mid_2, diff_2);
            }
        }
    }

    cout << mx_val;
}