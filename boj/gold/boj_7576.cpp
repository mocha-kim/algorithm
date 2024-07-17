#include <iostream>
#include <queue>
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int> > tomatos(n, vector<int>(m));
    vector<vector<bool> > is_checked(n, vector<bool>(m, false));
    queue<Position> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomatos[i][j];
            if (tomatos[i][j] == 1) {
                q.push({j, i});
                is_checked[i][j] = true;
            }
        }
    }

    Position cur;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Position next = cur + g_directions[i];
            if (next.x < 0 || next.x >= m || next.y < 0 || next.y >= n)
                continue;
            if (tomatos[next.y][next.x] != 0 || is_checked[next.y][next.x])
                continue;
            
            tomatos[next.y][next.x] = tomatos[cur.y][cur.x] + 1;
            is_checked[next.y][next.x] = true;
            q.push(next);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomatos[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << tomatos[cur.y][cur.x] - 1;
    return 0;
}