// Source: Problems/EGGS.jpg, from a teacher of mine
// Status: Solved
/* Note: You have M boxes and N eggs.
The N eggs are put onto a production belt in order, the i-th egg has a volume of A_i. At the end are the boxes.
You will move onto the next box if the current box is full.
Calculate the minimum capacity for each box so we can contain all egs.
Solution: Binary Search. Let P be the minimum capacity. We'll search on max(A_i) to sum(A_i) where i runs from 1 to n.

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 23/02/2026
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
int n, m;
vector<ll> a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("eggs.inp", "r", stdin); freopen("eggs.out", "w", stdout);

    cin >> n >> m;
    a.resize(n);

    ll mx = 0, sum = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }

    ll lo = mx, hi = sum, res;

    while(lo <= hi){
        ll mid = (lo + hi) >> 1;

        
        ll cur = 0, cnt = 1;
        bool ok = true;

        for (int i = 0; i < n; ++i){
            if (cur + a[i] > mid){
                ++cnt;
                cur = a[i];
                if (cnt > m){
                    ok = false;
                    break;
                }
            } 
            else  cur += a[i];
        }

        if (ok){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res;
}