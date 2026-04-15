// Source: Problems/DOAN.jpg, from a teacher of mine
// Status: Solved
/* Note: You have N segments, each segment is labeled by two intergers L and R, which is that start and endpoint of the segment.
You're asked to take a segment, then another one so that the one that was taken after fits inside the one before that.
Find the maximum amount of segments that you can take.

Let's say you have two segments A [L_a, R_a], B [L_b, R_b]. B fits inside A L_a <= L_b and R_b <= R_a.
We sort the array prioritizing smaller L values. If Ls are equal, larger R values
Why? So for every i segment, L_i >= L_j for all j < i. => We only need to check for R.
=> Now we find the longest non-increasing subsequence of R values.

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 23/02/2026
*/

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> dp;

struct segments{
    int l, r;
    bool operator < (const segments &other) const{
        if (l != other.l) return l < other.l;
        return r > other.r;
    }
};
vector<segments> s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("doan.inp", "r", stdin); freopen("doan.out", "w", stdout);

    cin >> n;
    s.resize(n);

    for (int i = 0; i < n; ++i){
        cin >> s[i].l >> s[i].r;
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < n; ++i){
        int target = -s[i].r;

        auto it = upper_bound(dp.begin(), dp.end(), target);

        if (it == dp.end()) dp.push_back(target);
        else *it = target;
    }

    cout << dp.size();
}
    