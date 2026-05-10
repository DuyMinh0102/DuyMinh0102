// Source: https://codeforces.com/contest/349/problem/B
// Status: Solved
/*
Note: Every digit (1 - 9) costs some amount to be paint. Determine the biggest number that can be painted.

Solution: The logic is simple:
- Prioritize painting as many digits as possible
- Iterate from front to back and see if we can increase any digit at any point with the remaining paint.

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: 07/05/2026 (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long

// Variables
int v, a[10];

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if (a.first != b.first) return a.first > b.first;

        return a.second < b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> v;
    bool paintable = false;
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

    for (int i = 1; i <= 9; ++i){
        cin >> a[i];
        if (a[i] <= v){
            paintable = true;
            pq.push(make_pair(a[i],i));
        }
    }

    if(!paintable){
        cout << -1;
        return 0;
    }

    int u = pq.top().second, p = pq.top().first;
    int amt = v / p;    
    string res(amt, (char)(u + '0'));   
    v %= p;

    for (int i = 0; i < amt; ++i){
        for (int d = 9; d > u; --d){
            if (v + p >= a[d]){
                res[i] = (char)(d + '0');
                v -= (a[d] - p);
                break;
            }
        }
    }

    cout << res;
}
