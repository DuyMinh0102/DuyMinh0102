#include <bits/stdc++.h>
using namespace std;
int n, k, a[105];
bool prime[100005];
k

void sang(){
    prime[0] = prime[1] = true;

    for (int i = 2; i * i <= 100000; ++i){
        if (!prime[i]){
            for (int j = i * i; j <= 100000; j += i){
                prime[j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("muanha.inp", "r", stdin); freopen("muanha.out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int sum = 0;
            for (int l = 0; l < i; ++l){

            }
        }
    }
}