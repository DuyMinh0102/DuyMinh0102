// Source: No source
// Status: Solved
/*
Note: Find the total unique area covered by N overlapping rectangles

Solution: Sweepline + Segment Tree

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 16/04/2026
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long

struct event{
    ll x, y1, y2, val;
    bool operator < (const event& other) const{
        if (x != other.x) return x < other.x;
        return val > other.val;
    }
};

// Variables
const int N = 1e5 + 5;
int n, cnt[8 * N];
ll sum[8 * N];
vector<ll> val_y;
vector<event> a;

void update(int k, int l, int r, int u, int v, int val){
    if (u > v || l > r) return;
    if (l == u && r == v) cnt[k] += val;
    else{
        int m = l + ((r - l) >> 1);
        update(k << 1, l, m, u, min(v, m), val);
        update((k << 1) | 1, m + 1, r, max(u, m + 1), v, val);
    }

    if (cnt[k] > 0) sum[k] = val_y[r + 1] - val_y[l];
    else if (l == r) sum[k] = 0;
    else sum[k] = sum[k << 1] + sum[(k << 1) | 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i){
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        a.push_back({x1, y1, y2, 1});
        a.push_back({x2, y1, y2, -1});
        val_y.push_back(y1);
        val_y.push_back(y2);
    }

    sort(val_y.begin(), val_y.end());
    val_y.erase(unique(val_y.begin(), val_y.end()), val_y.end());
    sort(a.begin(), a.end());

    ll ans = 0;
    ll lst = a[0].x;

    int mx_id = (int)val_y.size() - 2;

    for (event e : a){
        ans += (e.x - lst) * sum[1];
        lst = e.x;

        int l = lower_bound(val_y.begin(), val_y.end(), e.y1) - val_y.begin(),
        r = lower_bound(val_y.begin(), val_y.end(), e.y2) - val_y.begin() - 1;

        if (l <= r && mx_id >= 0) update(1, 0, mx_id, l, r, e.val);
    }

    cout << ans;
}