#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
    bool operator<(const Edge& other) const{
        return w < other.w;
    }
};

struct DSU{
    vector<int> parent;
    
    DSU(int n){
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i){
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    bool unite(int i, int j){
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j){
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    long long ans = 1;
    int edges_added = 0;
    int mod = 31011;
    
    for (int i = 0; i < m; ){
        int j = i;
        while (j < m && edges[j].w == edges[i].w){
            j++;
        }
        
        vector<Edge> group;
        for (int k = i; k < j; k++){
            group.push_back({dsu.find(edges[k].u), dsu.find(edges[k].v), edges[k].w});
        }
        
        DSU temp_dsu(n);
        int needed = 0;
        for (auto& e : group){
            if (e.u != e.v && temp_dsu.unite(e.u, e.v)) {
                needed++;
            }
        }
        
        if (needed > 0){
            int ways = 0;
            int k_size = group.size();
            
            for (int mask = 0; mask < (1 << k_size); mask++){
                if (__builtin_popcount(mask) == needed){
                    DSU check_dsu(n);
                    bool ok = true;
                    
                    for (int bit = 0; bit < k_size; bit++){
                        if ((mask >> bit) & 1) {
                            if (group[bit].u == group[bit].v || !check_dsu.unite(group[bit].u, group[bit].v)){
                                ok = false;
                                break;
                            }
                        }
                    }
                    
                    if (ok) ways++;
                }
            }
            
            ans = (ans * ways) % mod;
        }
        
        for (int k = i; k < j; k++){
            if (dsu.unite(edges[k].u, edges[k].v)){
                edges_added++;
            }
        }
        
        i = j;
    }
    
    if (edges_added != n - 1){
        cout << 0 << "\n";
    } else {
        cout << ans << "\n";
    }
    
    return 0;
}