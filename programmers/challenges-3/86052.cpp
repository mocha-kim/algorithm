#include <vector>
#include <algorithm>

using namespace std;

int g_row, g_col;
// dir: up right down left 순
int g_dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool g_is_visited[501][501][4];

int find_cycle_length(int i, int j, int dir, int length, vector<string> &grid) {
    if (g_is_visited[j][i][dir])
        return length;
    
    g_is_visited[j][i][dir] = true;
    
    int n_dir;
    switch(grid[j][i]) {
        case 'L':
            n_dir = dir == 0 ? 3 : dir - 1;
            break;
        case 'R':
            n_dir = dir == 3 ? 0 : dir + 1;
            break;
        default:
            n_dir = dir;
            break;
    }
    
    int n_i = i + g_dir[n_dir][0];
    if (n_i < 0)
        n_i = g_row - 1;
    else if (n_i >= g_row)
        n_i = 0;
    
    int n_j = j + g_dir[n_dir][1];
    if (n_j < 0)
        n_j = g_col - 1;
    else if (n_j >= g_col)
        n_j = 0;
    
    return find_cycle_length(n_i, n_j, n_dir, length + 1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int length;
    g_row = grid[0].size();
    g_col = grid.size();
    for (int j = 0; j < g_col; j++) {
        for (int i = 0; i < g_row; i++) {
            for (int dir = 0; dir < 4; dir++) {
                length = find_cycle_length(i, j, dir, 0, grid);
                if (length != 0)
                    answer.push_back(length);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}