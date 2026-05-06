#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int n, q;
struct services{
    int l, r;
    ll cost;
    services(int _l, int _r, ll _cost): l(_l), r(_r), cost(_cost) {}
    bool operator < (const services& other){
        return r < other.r;
    }
};
vector<services> Q;

int main(){
    
}