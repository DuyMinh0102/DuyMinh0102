// Source: Problems/BT_20260223.pdf
// Status: Solved
/*
Note: Read the pdf file please, it's too long to summarize.

Solution: Equations.

Author: Nguyen Duy Minh, High School for the Gifted, VNU - HCM.
Date:
*/

#include <bits/stdc++.h>
#define ll long double
using namespace std;
ll x_0, y_0, r, a, b, c, x_1, y_1, x_2, y_2;

bool is_inside(ll x0, ll y0, ll r, ll x, ll y){
    return ((x - x0)*(x - x0) + (y - y0)*(y - y0) <= r*r);
}

ll dist(ll x0, ll y0, ll x, ll y){
    return sqrt((x - x0)*(x - x0) + (y - y0)*(y - y0));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("blackbox.inp", "r", stdin); freopen("blackbox.out", "w", stdout);

    cin >> x_0 >> y_0 >> r >> a >> b >> c >> x_1 >> y_1 >> x_2 >> y_2;

    if (dist(x_0, y_0, x_2, y_2) < dist(x_0, y_0, x_1, y_1)){
        swap(x_1, x_2);
        swap(y_1, y_2);
    }

    ll small_r = dist(x_0, y_0, x_1, y_1);

    bool p1 = is_inside(x_0, y_0, r, x_1, y_1),
    p2 = is_inside(x_0, y_0, r, x_2, y_2);
    if (p1 && p2) cout << "YES";
    else if (!p1 && !p2){
        ll u_a = x_2 - x_1, u_b = y_2 - y_1,
        n_a = -u_b, n_b = u_a, n2_a = b, n2_b = -a;

        if (n_a*n2_b - n2_a*n_b == 0) cout << "YES";
        else cout << "NO";
    }
    else{
        ll pt_c = -(a*x_2 + b*y_2);

        if ((ll)abs(a*x_0 + b*y_0 + pt_c)/sqrt(a*a + b*b) <= small_r) cout << "YES";
        else cout << "NO";
    }
}