// Source:
// Status:
/*
Note: 

Solution:

Author: Nguyen Duy Minh - studying at High School for the Gifted, VNU - HCM.
Date: (DD/MM/YYYY).
*/
#include <bits/stdc++.h>
using namespace std;

// Debug
#define dbg(testingLine, debugDescription, testedVariable) cerr << "Debug on line " << testingLine << ': ' << debugDescription << ' ' << testedVariable << '\n';

// Config
#define pb push_back
#define ll long long
const int N = 5005;

// Variables
int n;
vector<int> g[N], subtr_hash(N, 0);
map<vector<int>, int> hashmap;
map<int, ll> hashfreq;
int nxt_id = 0;

void dfs(int u, int p){
  vector<int> hashchild;

  for (int v : g[u]){
    if (v == p) continue;
    dfs(v, u);
    hashchild.pb(subtr_hash[v]);
  }

  sort(hashchild.begin(), hashchild.end());

  if (hashmap.find(hashchild) == hashmap.end()) hashmap[hashchild] = ++nxt_id;

  subtr_hash[u] = hashmap[hashchild];
  ++hashfreq[subtr_hash[u]];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; ++i){
      int u, v; cin >> u >> v;
      g[u].pb(v); g[v].pb(u);
    }

    dfs(1, 0);

    ll total = 0;
    for (auto [val, count] : hashfreq){
      total += count * (count - 1) / 2;
    }

    cout << total;
}
