#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, dc[] = {-1, 0, 1, 0}, dr[] = {0, -1, 0, 1};
char g[N][N], direct[] = {'L', 'U', 'R', 'D'};
struct coord{
    int x, y;
    char direction;
    coord() {}
    coord (int _x, int _y, char _d) : x(_x), y(_y), direction(_d) {}
}; 
queue<coord> ms;
coord a;
pair<int, char> dist[N][N], dist_a[N][N];

bool inside(int x, int y){
    return x >= 1 && x <=n && y >= 1 && y <= m;
}

void bfs(){
    while(!ms.empty()){
        int r = ms.front().x, c = ms.front().y;
        ms.pop();

        for (int i = 0; i < 4; ++i){
            int x = r + dr[i], y = c + dc[i];

            if (!inside(x, y) || g[x][y] == '#') continue;
            if (dist[x][y].first > dist[r][c].first + 1 || dist[x][y].first == -1){
                dist[x][y].first = dist[r][c].first + 1;
                dist[x][y].second = direct[i];
                ms.push(coord(x, y, direct[i]));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    map<char, int> id; 
    id['L'] = 0;
    id['U'] = 1;
    id['R'] = 2;
    id['D'] = 3;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            dist[i][j] = dist_a[i][j] = {-1, '%'};
            cin >> g[i][j];
            if (g[i][j] == 'A'){
                a = coord(i, j, '*');
                dist_a[i][j].first = 0;
            }
            else if (g[i][j] == 'M'){
                ms.push(coord(i, j, '&'));
                dist[i][j].first = 0;
            }
        }
    }

    bfs();

    ms.push(a);
    while(!ms.empty()){
        int r = ms.front().x, c = ms.front().y;
        char dir = ms.front().direction;
        ms.pop();
        int d;
        if (dir == '*') d = -1;
        else{
            d = id[dir];
            if (d < 2) d += 2;
            else d -= 2;
        }
        

        for (int i = 0; i < 4; ++i){
            int x = r + dr[i], y = c + dc[i];

            if (!inside(x, y) || g[x][y] != '.' || d == i) continue;
            if (dist[x][y].first != -1 && dist[x][y].first <= dist_a[r][c].first + 1) continue;
            if (dist_a[x][y].first > dist_a[r][c].first + 1 || dist_a[x][y].first == -1){
                dist_a[x][y].first = dist_a[r][c].first + 1;
                dist_a[x][y].second = direct[i];
                ms.push(coord(x, y, direct[i]));
            }
        }
    }

    int mx = 0, x, y;
    bool possible = false;

    for (int i = 1; i <= n; ++i){
        if (dist_a[i][1].first != -1){
            x = i; y = 1;
            possible = true;
            break;
        }
        if (dist_a[i][m].first != -1){
            x = i; y = m;
            possible = true;
            break;
        }
    }

    if (!possible){
        for (int i = 1; i <= m; ++i){
            if (dist_a[1][i].first != -1){
                x = 1; y = i;
                possible = true;
                break;
            }
            if (dist_a[n][i].first != -1){
                x = n, y = i;
                possible = true;
                break;
            }
        }
    }

    if (!possible){
        cout << "NO";
        return 0;
    }

    vector<char> res;
    while(dist_a[x][y].second != '%'){
        res.push_back(dist_a[x][y].second);
        int d = id[dist_a[x][y].second];
        x -= dr[d];
        y -= dc[d];
    }
    cout << "YES\n" << res.size() << '\n';
    reverse(res.begin(), res.end());
    for (char c : res) cout << c;
}