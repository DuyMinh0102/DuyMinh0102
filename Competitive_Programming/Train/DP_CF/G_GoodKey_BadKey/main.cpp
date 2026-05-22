// Source: https:// codeforces.com/contest/1703/problem/G/
// Status:
/*
Note: You need to open all chests 1 to N. Each chest you can use either:
- Good key: costs k coins to buy, gets all rewards in current chest
- Bad key: costs none, but each time used, halves the amount of coins of every
unopened chests, including the current. At start: have no keys

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 20/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable)                     \
    cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' \
         << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 100005;

// Variables
int t, n, k;
ll c[N], pref[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;

        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
            pref[i] = pref[i - 1] + c[i] - k;
        }

        ll mx = -1e18;

        for (int i = 0; i <= n; ++i) {
            ll sum = pref[i];

            for (int j = i + 1; j <= min(n, i + 31); ++j) {
                ll half = c[j];
                int times = j - i;

                sum += (half >>= times);
            }

            mx = max(mx, sum);
        }

        cout << mx << '\n';
    }
}
