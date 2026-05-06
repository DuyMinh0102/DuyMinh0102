// Source: Problems/MTWALK.jpg
// Status: Solved
/*Note: Given a N x N grid, find a 4 directional path from (1, 1) to (N, N) that minimizes
the difference between the value of the largest and smallest cell on the path.
Solution: Binary search the difference, use BFS to check if there exists a path with such difference or less.

Author: Nguyen Duy  Minh - High School for the Gifted, VNU-HCM.
Date: 23/02/2026
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, h[N][N], mn = 110, mx = 0;

int dc[] = {-1, 0, 1, 0}, dr[] = {0, -1, 0, 1};

bool valid(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

bool bfs(int L, int R){
    if (h[1][1] < L || h[1][1] > R) return false;

    bool check[N][N] = {false};
    queue<pair<int, int>> q;
    check[1][1] = true;
    q.push({1, 1});

    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();

        if (r == n && c == n) return true;

        for (int i = 0; i < 4; ++i){
            int x = r + dr[i], y = c + dc[i];

            if (valid(x, y) && !check[x][y]){
                if (h[x][y] >= L && h[x][y] <= R){
                    check[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

    return false;
}

bool check(int diff){
    for (int l = 0; l <= (110 - diff); ++l){
        int r = l + diff;
        if (bfs(l, r)) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("mtwalk.inp", "r", stdin);
    freopen("mtwalk.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> h[i][j];
            mn = min(mn, h[i][j]);
            mx = max(mx, h[i][j]);
        }
    }

    mx = mx - mn;
    mn = 0;
    int ans = mx;
    while(mn <= mx){
        int mid = (mn + mx) / 2;

        if (check(mid)){
            ans = mid;
            mx = mid - 1;
        }
        else mn = mid + 1;
    }

    cout << ans;
}