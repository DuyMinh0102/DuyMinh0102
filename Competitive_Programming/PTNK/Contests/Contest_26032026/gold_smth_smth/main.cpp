#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, l, r, m;
ll g, v;

int main() {
    cin >> n;

    cout << "? 0 " << n - 1 << '\n' << flush;
    cin >> g;

    l = 0;
    r = n - 1;

    while (l < r) {
        m = l + (r - l) / 2;
        
        cout << "? " << l << " " << m << '\n' << flush;
        cin >> v;

        if (v == g) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << "! " << l << '\n' << flush;

    return 0;
}