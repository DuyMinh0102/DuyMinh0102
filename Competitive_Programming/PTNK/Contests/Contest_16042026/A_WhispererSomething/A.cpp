// Source: No source
// Status: Solved
/*
Note: Given N intergers, where the i-th interger represents the i-th character's frequency.
The problem states: find the optimal prefix-free binary encoding for a set of characters to minimize the total number of bits needed
to transmit a secret message.
Rule: No character's binary code can be a prefix of another  character's code to ensure ambiguous decoding.

Solution: Huffman Coding algorithm, but just counting the total bits.
Total bit count is equivalent to the sum of all internal merged nodes created during the Huffman process.

Author: Nguyen Duy Minh - High School for the Gifted, VNU - HCM.
Date: 16/04/2026
*/
#include <bits/stdc++.h>
using namespace std;

// Config
#define ll long long

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n'; 

// Variables
int n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i){
        ll f; cin >> f;

        pq.push(f);
    }

    ll ans = 0;
    while(pq.size() > 1){
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    cout << ans;
}