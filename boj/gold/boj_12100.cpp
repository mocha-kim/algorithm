#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 20

int g_n;
int g_max = 0;

enum Direction { UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3 };

class Board {
public:
    int data[MAX][MAX];

    Board(int size) : size(size) {}
    void move(Direction dir);

private:
    int size;

    void rotate(bool isClockwise);
    void move_left();
};

void dfs(int count, Board& board);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g_n;
    Board board(g_n);
    for (int i = 0; i < g_n; i++) 
        for (int j = 0; j < g_n; j++)
            cin >> board.data[i][j];

    dfs(0, board);
    cout << g_max;
    return 0;
}

void dfs(int count, Board& board) {
    if (count == 5) {
        for (int i = 0; i < g_n; i++)
            for (int j = 0; j < g_n; j++)
                g_max = max(g_max, board.data[i][j]);
        return;
    }

    int backup[MAX][MAX];
    memcpy(backup, board.data, sizeof(board.data));
    for (int i = 0; i < 4; i++) {
        board.move((Direction)i);
        dfs(count + 1, board);
		memcpy(board.data, backup, sizeof(board.data));
    }
}

void Board::move(Direction dir) {
    switch (dir) {
    case Direction::UP:
        rotate(false);
        move_left();
        rotate(true);
        break;
    case Direction::RIGHT:
        rotate(true);
        rotate(true);
        move_left();
        rotate(false);
        rotate(false);
        break;
    case Direction::DOWN:
        rotate(true);
        move_left();
        rotate(false);
        break;
    case Direction::LEFT:
        move_left();
        break;
    }
}

void Board::rotate(bool isClockwise) {
    int rotated[MAX][MAX];
    if (isClockwise) {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                rotated[j][size - 1 - i] = data[i][j];
    } else {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                rotated[size - 1 - j][i] = data[i][j];
    }

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = rotated[i][j];
}

void Board::move_left() {
    for (int i = 0; i < size; i++) {
        int idx = 0;
        for (int j = 0; j < size; j++) {
            if (data[i][j] == 0) 
                continue;

            int value = data[i][j];
            data[i][j] = 0;
            if (data[i][idx] == 0)
                data[i][idx] = value;
            else if (data[i][idx] == value)
                data[i][idx++] *= 2;
            else
                data[i][++idx] = value;
        }
    }
}