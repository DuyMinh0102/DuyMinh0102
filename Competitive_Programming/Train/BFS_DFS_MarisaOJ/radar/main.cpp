#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db double

const int N = 1005;
int n;
ll X[N], Y[N], D[N], M;
bool V[N];

ll dist(int i, int j) {
    return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
        D[i] = 8e18;
    }

    D[0] = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!V[j] && (u == -1 || D[j] < D[u])) {
                u = j;
            }
        }

        V[u] = true;
        M = max(M, D[u]);

        for (int v = 0; v < n; ++v) {
            if (!V[v]) {
                D[v] = min(D[v], dist(u, v));
            }
        }
    }

    cout << fixed << setprecision(6) << sqrt((db)M) / 2.0 << "\n";

    return 0;
}