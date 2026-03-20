#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    set<long long> st;
    auto it = st.end();

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            auto found = st.find(x);

            if (found == st.end()) {
                int sz = st.size();
                auto res = st.insert(x).first;
                if (sz == 0) {
                    it = res;
                } else if (sz % 2 == 0) {
                    if (x >= *it) it++;
                } else {
                    if (x < *it) it--;
                }
            } else {
                int sz = st.size();
                if (found == it) {
                    if (sz % 2 == 0) it++;
                    else it--;
                } else {
                    if (sz % 2 == 0 && x < *it) it++;
                    else if (sz % 2 != 0 && x > *it) it--;
                }
                st.erase(found);
            }
        } else {
            if (st.size() % 2 != 0) {
                cout << *it << "\n";
            } else {
                long long v1 = *it;
                long long v2 = *next(it);
                if ((v1 + v2) % 2 == 0) {
                    cout << (v1 + v2) / 2 << "\n";
                } else {
                    cout << fixed << setprecision(1) << (v1 + v2) / 2.0 << "\n";
                }
            }
        }
    }

    return 0;
}