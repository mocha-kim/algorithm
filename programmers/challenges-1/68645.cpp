#include <string>
#include <vector>

using namespace std;

enum DIR : int {
	Down,
	Right,
	Up
};

int g_dir[3][2] = {{0, 1}, {1, 0} , {-1, -1}};

vector<int> solution(int n) {
    vector<vector<int> > triangle(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		triangle[i].assign(i + 1, 0);
	}
	triangle[0][0] = 1;
    int cur = 2, row = 0, col = 1, layer = 0, dir = Down;
    int max = n * (n + 1) / 2;
    while (cur <= max) {
        triangle[col][row] = cur;
        if (col - layer == row) {
			if (triangle[col - 1][row - 1]) {
				if (dir != Down) {
					layer++;
				}
				dir = Down;
			} else {
            	dir = Up;
			}
        } else if (col == n - layer - 1 && row == layer){
			dir = Right;
        }
        row += g_dir[dir][0];
        col += g_dir[dir][1];
        cur++;
    }
    vector<int> answer;
	for (vector<int> line : triangle) {
		answer.insert(answer.end(), line.begin(), line.end());
	}
    return answer;
}