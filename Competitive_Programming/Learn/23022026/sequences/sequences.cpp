// Source: Problems/SEQUENCES.jpg, from a teacher of mine
// Status: Solved
/* Note: Given N positive intergers, find the longest W-sequence
W-sequence:
    - A sequence of odd length
    - The first (length + 1) / 2 elements are strictly increasing
    - The last (length + 1) / 2 elements are strictly decreasing
Solution: do LIS from 1 to n and LDS from n to 1.
let l[i] = the length of the longest strictly increasing subsequence that ends at i
let r[i] = the length of the longest strictly decreasing subsequence that starts at i

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 23/02/2026
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], l[N], r[N];

vector<int> solve(int arr[]){
    vector<int> res(n), t;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(t.begin(), t.end(), arr[i]);
        if(it == t.end()){
            t.push_back(arr[i]);
            res[i] = t.size();
        } else{
            *it = arr[i];
            res[i] = distance(t.begin(), it) + 1;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    freopen("sequences.inp", "r", stdin);    
    freopen("sequences.out", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> L = solve(a);
    for(int i = 0; i < n; i++) l[i] = L[i];
    
    reverse(a, a + n);
    vector<int> R = solve(a);
    for(int i = 0; i < n; i++) r[n - i - 1] = R[i];
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, 2 * min(l[i], r[i]) - 1);
    
    cout << ans;
    return 0;
}