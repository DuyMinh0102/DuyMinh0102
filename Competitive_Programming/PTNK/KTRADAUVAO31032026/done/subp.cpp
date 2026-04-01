#include <bits/stdc++.h>
using namespace std;
stack<int> st;
string s;
int len = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("subp.inp", "r", stdin); freopen("subp.out", "w", stdout);

    cin >> s;
    int n = s.size(), mx_1 = 0, mx_2 = 0;

    for (int i = 0; i < n; ++i){
        if (s[i] == '(') st.push(i);
        else if (!st.empty()){
            len += 2;
            st.pop();
        }
        else if (st.empty()) len = 0;
        mx_1 = max(mx_1, len);
    }

    while(!st.empty()) st.pop();

    len = 0;
    for (int i = n - 1; i >= 0; --i){
        if (s[i] == ')') st.push(i);
        else if (!st.empty()){
            len += 2;
            st.pop();
        }
        else if (st.empty()) len = 0;
        mx_2 = max(mx_2, len);
    }

    cout << min(mx_1, mx_2);
}