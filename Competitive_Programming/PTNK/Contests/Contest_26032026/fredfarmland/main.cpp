// Source: ..
// Status: Solved
/*
Note: ..

Solution: ..

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date: 26/03/2026 (DD/MM/YYYY).
*/

#include <bits/stdc++.h>
using namespace std;
int n;
struct points{
    int x, y;
    points(int _x, int _y): x(_x), y(_y) {}
};
vector<points> p;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    p.resize(n);

    for (int i = 0; i < n; ++i){
        cin >> p[i].x >> p[i].y;
    }

    double area = 0.0;

    for (int i = 0; i < n; ++i){
        int j = (i + 1) % n;

        area += (p[j].x - p[i].x) * (p[j].y + p[i].y) / 2.0;
    }

    area = abs(area);

    cout << fixed << setprecision(1) << area;
}