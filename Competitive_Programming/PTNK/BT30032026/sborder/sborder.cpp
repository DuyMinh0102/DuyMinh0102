// Source: Problems/BT_20260330.pdf
// Status: Solved
/*
Note: A string Q is considered a border if both the prefix and the suffix of the string equals to Q.
A string can have multiple borders.
Find all borders of S. Output: print out the length of different borders of S.

Solution: Z-function.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 30/03/2026 (DD/MM/YYYY)
*/

#include <bits/stdc++.h>
using namespace std;
int len;
string s;
vector<int> z;

vector<int> z_function(string s){
    vector<int> Z(len, 0);

    int l = 0,r = 0;

    for (int i = 1; i < len; ++i){
        if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);
        while(i + Z[i] < len && s[Z[i]] == s[i + Z[i]]) ++Z[i];
        if (i + Z[i] > r){
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("sborder.inp", "r", stdin); freopen("sborder.out", "w", stdout);

    cin >> s;
    len = s.size();
    z = z_function(s);
    vector<int> bien;

    for (int i = len - 1; i >= 0; --i){
        if (i + z[i] == len) bien.push_back(z[i]);
    }

    for (int i = 0; i < bien.size(); ++i) cout << bien[i] << ' ';
}