#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int x, y, pref[N];
vector<int> a(N), b(N);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> x >> y;

    char num;
    int pos = 1;
    a[0] = b[0] = 0;
    map<int, int> m;

    while(cin >> num){
        int x = num - '0';

        a[pos] = a[pos - 1] + (x == 1);
        b[pos] = b[pos - 1] + (x == 0);
        pos++;
    }

    for (int i = 1; i < pos; ++i){
        a[i] *= x;
        b[i] *= y;
    }

    for (int i = 1; i < pos; ++i){
        a[i] -= b[i];
    }

    ++m[0];
    int res = 0;
    for (int i = 1; i < pos; ++i){
        res += m[a[i]];
        ++m[a[i]];
    }

    cout << res;
}