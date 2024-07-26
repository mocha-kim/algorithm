#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000001

struct position {
    int x;
    int y;
    bool is_wall_broken;

    position(int x, int y, bool is_wall_broken) : x(x), y(y), is_wall_broken(is_wall_broken) {}
};

int g_dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for (int i = 0; i < n; i++)
        cin >> map[i];
    
    queue<position> q;
    vector<vector<vector<int>>> distance(n, vector<vector<int>>(m, vector<int>(2, MAX)));
    distance[0][0][0] = 1;
    q.push(position(0, 0, false));
    while(!q.empty()) {
        position cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + g_dir[i][0];
            int ny = cur.y + g_dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            bool is_next_wall_broken = cur.is_wall_broken;
            if (map[nx][ny] == '0') {
                if (distance[nx][ny][is_next_wall_broken] != MAX)
                    continue;
                distance[nx][ny][is_next_wall_broken] = distance[cur.x][cur.y][is_next_wall_broken] + 1;
                q.push(position(nx, ny, is_next_wall_broken));
            } 
            else if (!is_next_wall_broken) {
                distance[nx][ny][true] = distance[cur.x][cur.y][false] + 1;
                q.push(position(nx, ny, true));
            }
        }
    }

    int answer = min(distance[n - 1][m - 1][0], distance[n - 1][m - 1][1]);
    cout << (answer == MAX ? -1 : answer);
    return 0; 
}