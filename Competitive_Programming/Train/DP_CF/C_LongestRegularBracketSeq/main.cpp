// Source: https://codeforces.com/contest/5/problem/C
// Status: Solved
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 21/4/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Config
#define ll long long

// Variables
string s;
int mx_len = 0, cnt = 1;
stack<int> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    st.push(-1);

    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '(') st.push(i);
        else{
            st.pop();

            if (st.empty()) st.push(i);
            else{
                int cur_len = i - st.top();

                if (cur_len > mx_len){
                    mx_len = cur_len;
                    cnt = 1;
                }
                else if (cur_len == mx_len) ++cnt;
            }
        }
    }

    cout << mx_len << ' ' << cnt;
}