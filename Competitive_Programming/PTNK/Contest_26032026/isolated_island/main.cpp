#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct points{
    ll x, y;
};
vector<points> p;
points coord;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;

    cin >> coord.x >> coord.y;

    bool inside = false;

    for (int i = 0; i < n; ++i){
        int j = (i + 1) % n;

        points p1 = p[i], p2 = p[j];

        ll cross = (p1.x - coord.x) * (p2.y - coord.y) - (p1.y - coord.y) * (p2.x - coord.x);

        if (cross == 0){
            if (coord.x >= min(p1.x, p2.x) && coord.x <= max(p1.x, p2.x)
                && coord.y >= min(p1.y, p2.y) && coord.y <= max(p1.y, p2.y)){
                    cout << "BOUNDARY";
                    return 0;
                }
        }

        if ((p1.y > coord.y) != (p2.y > coord.y)){
            cross = (p2.x - p1.x) * (coord.y - p1.y) - (p2.y - p1.y) * (coord.x - p1.x);

            if (p2.y > p1.y){if(cross > 0) inside = !inside;}
            else if (cross < 0) inside = !inside;
        }
    }

    if(inside) cout <<"INSIDE";
    else cout << "OUTSIDE";
}