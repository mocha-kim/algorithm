#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Position {
    int x;
    int y;
	
    Position(int x, int y) : x(x), y(y) {}
	
    Position operator+(const Position& other) const {
        return { x + other.x, y + other.y };
    }
};

bool visit(int i, int j, vector<vector<int>> &a, vector<vector<bool>> &is_visited);
	
Position g_directions[4] = { Position(0, 1), Position(1, 0), Position(0, -1), Position(-1, 0) };
int g_n, g_l, g_r;

int main() {
	cin >> g_n >> g_l >> g_r;
	vector<vector<int>> a(g_n, vector<int>(g_n));
	for (int i = 0; i < g_n; i++)
		for (int j = 0; j < g_n; j++)
			cin >> a[i][j];
	
	int days = 0;
	bool is_moved = true;
	while (is_moved) {
		is_moved = false;
		vector<vector<bool>> is_visited(g_n, vector<bool>(g_n, false));
		
		for (int i = 0; i < g_n; i++)
			for (int j = 0; j < g_n; j++)
				if (!is_visited[i][j])
					if (visit(i, j, a, is_visited))
						is_moved = true;
		
		if (is_moved)
			days++;
	}
	
	cout << days;
	return 0;
}

// returns if population moved
bool visit(int i, int j, vector<vector<int>> &a, vector<vector<bool>> &is_visited) {
	queue<Position> bfs_queue;
	vector<Position> united_countries;
	
	bfs_queue.push(Position(j, i));
	united_countries.push_back(Position(j, i));
	
	is_visited[i][j] = true;
	int total_population = a[i][j];
	
	while (!bfs_queue.empty()) {
		Position cur = bfs_queue.front();
		bfs_queue.pop();
		
        for (const Position& dir : g_directions) {
			Position next = cur + dir;
			if (next.x < 0 || next.x >= g_n || next.y < 0 || next.y >= g_n)
				continue;
			if (is_visited[next.y][next.x])
				continue;
			
			int gap = abs(a[next.y][next.x] - a[cur.y][cur.x]);
			if (gap >= g_l && gap <= g_r) {
				bfs_queue.push(next);
				united_countries.push_back(next);
				
				is_visited[next.y][next.x] = true;
				total_population += a[next.y][next.x];
			}
		}
	}
	
	if (united_countries.size() < 2)
		return false;
	
	int new_population = total_population / united_countries.size();
	for (const Position &pos : united_countries) {
		a[pos.y][pos.x] = new_population;
	}
	return true;
}