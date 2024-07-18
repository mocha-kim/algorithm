#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Position {
    int x;
    int y;
	
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}
	
    Position operator+(const Position& other) const {
        return { x + other.x, y + other.y };
    }
};

Position g_directions[4] = { Position(0, 1), Position(1, 0), Position(0, -1), Position(-1, 0) };

int main() {
    int n, m;
    cin >> n >> m;

    Position destination;
    vector<vector<int>> map(n, vector<int>(m, n * m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                map[i][j] = -1;
            } else if (map[i][j] == 2) {
                map[i][j] = 0;
                destination = Position(j, i);
            }
        }
    }

    queue<Position> q;
    q.push(destination);
    while(!q.empty()) {
        Position cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Position next = cur + g_directions[i];
            if (next.x < 0 || next.y >= m || next.y < 0 || next.y >= n)
                continue;
            if (map[next.y][next.x] != -1) 
                continue;
            map[next.y][next.x] = map[cur.y][cur.x] + 1;
            q.push(next);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}