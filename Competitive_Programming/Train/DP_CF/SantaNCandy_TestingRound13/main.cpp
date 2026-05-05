#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> order;

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int base = 0, sum = 0;

    cin >> n;

    for (int i = 1; i <= n; ++i){
        ++base;
        if (sum + base > n){
            base = n - sum;
            if(order.empty()) order.push_back(base);
            else order.back() += base;
            break;
        }

        sum += base;
        order.push_back(base);
    }

    cout << order.size() << '\n';

    for (int i : order) cout << i << ' ';
}