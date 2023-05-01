#include <string>
#include <vector>
#include <queue>

using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int g_dx[4] = {1, 0, -1, 0};
int g_dy[4] = {0, 1, 0, -1};

struct cell {
    int x;
    int y;
    int dir;
    int cost;
    
    cell(int x, int y, int d, int c) {
        this->x = x;
        this->y = y;
        dir = d;
        cost = c;
    }
};

struct compare {
    bool operator()(cell &a, cell &b) {
        return a.cost < b.cost;
    }
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    int cost[25][25];
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            cost[i][j] = 999999;
        }
    }
    for (int i = 0; i < 4; i++) {
        cost[0][0] = 0;
    }
    
    int answer = 2147483647;
    priority_queue<cell, vector<cell>, compare> pq;
    pq.push(cell(0, 0, -1, 0));
    while (!pq.empty()) {
        cell cur = pq.top();
        pq.pop();
        if (cur.x == n - 1 && cur.y == n - 1) {
            answer = min(answer, cost[cur.y][cur.x]);
            continue;
        }
        int next_x, next_y, next_cost;
        for (int i = 0; i < 4; i++) {
            next_x = cur.x + g_dx[i];
            next_y = cur.y + g_dy[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && board[next_y][next_x] == 0) {
                if (cur.dir == -1 || cur.dir == i) {
                    next_cost = cur.cost + 100;
                } else {
                    next_cost = cur.cost + 600;
                }
                if (next_cost <= cost[next_y][next_x]) {
                    cost[next_y][next_x] = next_cost;
                    pq.push(cell(next_x, next_y, i, next_cost));
                }
            }
        }
    }
    return answer;
}