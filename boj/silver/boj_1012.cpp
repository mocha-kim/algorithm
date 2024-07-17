#include <iostream>
#include <cstring>
using namespace std;

bool g_board[50][50] = { false };
int g_dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void dfs(int x, int y, int m, int n);
	
int main() {
	int t, m, n, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> k;
		memset(g_board, false, sizeof(g_board));
		int x, y, count = 0;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			g_board[y][x] = true;
		}
		
		// start warm count
		for (y = 0; y < n; y++) {
			for (x = 0; x < m; x++) {
				if (!g_board[y][x])
					continue;
				dfs(x, y, m, n);
				count++;
			}
		}
		cout << count << "\n";
	}
    return 0;
}

void dfs(int x, int y, int m, int n) {
	g_board[y][x] = false;
	for (int i = 0; i < 4; i++) {
		int next_x = x + g_dir[i][0];
		int next_y = y + g_dir[i][1];
		if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
			continue;
		if (!g_board[next_y][next_x])
			continue;
		dfs(next_x, next_y, m, n);
	}
}