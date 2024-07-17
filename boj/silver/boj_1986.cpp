#include <iostream>
#include <vector>
using namespace std;

enum class TileType {
	QUEEN = 1,
	KNIGHT = 2,
	PAWN = 3,
	DANGER = 4,
	
	EMPTY = -1,
};

void check_queen_path(int r, int c, vector<vector<TileType>> &board);
void check_knight_path(int r, int c, vector<vector<TileType>> &board);

int g_n, g_m;

int g_queen_dirs[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
int g_knight_dirs[8][2] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

int main() {
	cin >> g_n >> g_m;
	
	vector<vector<TileType>> board(g_n, vector<TileType>(g_m, TileType::EMPTY));
	
	int queen_count;
	cin >> queen_count;
	for(int i = 0; i < queen_count; i++) {
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = TileType::QUEEN;
	}
	
	int knight_count;
	cin >> knight_count;
	vector<vector<int>> knights(knight_count, vector<int>(2));
	for(int i = 0; i < knight_count; i++) {
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = TileType::KNIGHT;
	}
	
	int pawn_count;
	cin >> pawn_count;
	vector<vector<int>> pawns(pawn_count, vector<int>(2));
	for(int i = 0; i < pawn_count; i++) {
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = TileType::PAWN;
	}
	
	for (int i = 0; i < g_n; i++) {
		for (int j = 0; j < g_m; j++) {
			switch(board[i][j]) {
				case TileType::QUEEN:
					check_queen_path(i, j, board);
					break;
				case TileType::KNIGHT:
					check_knight_path(i, j, board);
					break;
				default:
					break;
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < g_n; i++)
		for (int j = 0; j < g_m; j++)
			if (board[i][j] == TileType::EMPTY)
				count++;
	cout << count;
	return 0;
}

void check_queen_path(int r, int c, vector<vector<TileType>> &board) {
    for (const auto &direction : g_queen_dirs) {
		int delta_r = direction[0];
		int delta_c = direction[1];
		int next_r = r;
		int next_c = c;
		while (true) {
			next_r += delta_r;
			next_c += delta_c;
			if (next_r < 0 || next_r >= g_n || next_c < 0 || next_c >= g_m)
				break;
			
			if (board[next_r][next_c] == TileType::EMPTY)
				board[next_r][next_c] = TileType::DANGER;
			else if (board[next_r][next_c] < TileType::DANGER)
				break;
		}
    }
}

void check_knight_path(int r, int c, vector<vector<TileType>> &board) {
    for (const auto &direction : g_knight_dirs) {
		int next_r = r + direction[0];
		int next_c = c + direction[1];
		if (next_r < 0 || next_r >= g_n || next_c < 0 || next_c >= g_m)
			continue;
		
		if (board[next_r][next_c] == TileType::EMPTY)
			board[next_r][next_c] = TileType::DANGER;
    }
}