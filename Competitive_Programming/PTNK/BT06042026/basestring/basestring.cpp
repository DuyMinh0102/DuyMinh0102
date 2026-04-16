// Source: Problems/BT_20260406.pdf
// Status: Solved
/*
Note: Given two string S and T, find the base string q.
Let q^i be the string q repeated i times
example: abc^3 = abcabcabc
Find a q so that exists two interger i and j so:
q^i = S
q^j = T
q is as long as possible

Solution: use Z-function.

Author: Nguyen Duy Minh - High School for the Gifted, VNU - HCM
Date: 06/04/2026
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
string s, t;
int s_z[N] = {0}, t_z[N] = {0}, start;

void z_function(int Z[], string st, int sz){
    for (int i = 1, l = 0, r = 0; i < sz; ++i){
        if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);

        while(i + Z[i] < sz && st[Z[i]] == st[i + Z[i]]) ++Z[i];

        if (i + Z[i] - 1 > r){
            l = i;
            r = i + Z[i] - 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("basestring.inp", "r", stdin); freopen("basestring.out", "w", stdout);

    cin >> s >> t;
    int n = s.size(), m = t.size();

    int l = __gcd(n, m);

    if (s.substr(0, l) != t.substr(0, l)){
        cout << "NO";
        return 0;
    }
    string b = s.substr(0, l);

    z_function(s_z, s, n);
    if (l < n && s_z[l] != n - l){
        cout << "NO";
        return 0;
    }

    z_function(t_z, t, m);
    if (l < m && t_z[l] != m - l){
        cout << "NO";
        return 0;
    }

    cout << s.substr(0, l);
}