#include <vector>

using namespace std;

enum POS {
    StartX,
    StartY,
    EndX,
    EndY,
};

enum DIR {
    Up,
    Down,
    Right,
    Left,
};

enum TYPE {
    Empty,
    Fill,
    Border,
};

typedef struct s_info {
    TYPE up = TYPE::Empty;
    TYPE down = TYPE::Empty;
    TYPE right = TYPE::Empty;
    TYPE left = TYPE::Empty;
    bool visited = false;
} t_info;

vector<vector<int> > gDir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int gAnswer = 99999;
vector<vector<t_info> > gMap(51, vector<t_info>(51));
vector<int> gItem(2);

void dfs(int cur, int x, int y) {
    if (gMap[y][x].visited)
        return;
    if (x == gItem[0] && y == gItem[1]) {
        if (cur < gAnswer)
            gAnswer = cur;
        return;
    }
    
    gMap[y][x].visited = true;
    
    if (gMap[y][x].up == TYPE::Border)
        dfs(cur + 1, x + gDir[DIR::Up][0], y + gDir[DIR::Up][1]);
    if (gMap[y][x].down == TYPE::Border)
        dfs(cur + 1, x + gDir[DIR::Down][0], y + gDir[DIR::Down][1]);
    if (gMap[y][x].right == TYPE::Border)
        dfs(cur + 1, x + gDir[DIR::Right][0], y + gDir[DIR::Right][1]);
    if (gMap[y][x].left == TYPE::Border)
        dfs(cur + 1, x + gDir[DIR::Left][0], y + gDir[DIR::Left][1]);
    
    gMap[y][x].visited = false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (vector<int> rect : rectangle) {
        for (int y = rect[POS::StartY]; y <= rect[POS::EndY]; y++) {
            for (int x = rect[POS::StartX]; x <= rect[POS::EndX]; x++) {
                if (x == rect[POS::StartX] || x == rect[POS::EndX]) {
                    if (y != rect[POS::StartY] && gMap[y][x].down != TYPE::Fill)
                        gMap[y][x].down = TYPE::Border;
                    if (y != rect[POS::EndY] && gMap[y][x].up != TYPE::Fill)
                        gMap[y][x].up = TYPE::Border;
                } else {
                    if (y != rect[POS::StartY])
                        gMap[y][x].down = TYPE::Fill;
                    if (y != rect[POS::EndY])
                        gMap[y][x].up = TYPE::Fill;
                }
                if (y == rect[POS::StartY] || y == rect[POS::EndY]) {
                    if (x != rect[POS::StartX] && gMap[y][x].left != TYPE::Fill)
                        gMap[y][x].left = TYPE::Border;
                    if (x != rect[POS::EndX] && gMap[y][x].right != TYPE::Fill)
                        gMap[y][x].right = TYPE::Border;
                } else {
                    if (x != rect[POS::StartX])
                        gMap[y][x].left = TYPE::Fill;
                    if (x != rect[POS::EndX])
                        gMap[y][x].right = TYPE::Fill;
                }
            }
        }
    }
    gItem[0] = itemX;
    gItem[1] = itemY;
    
    dfs(0, characterX, characterY);
    return gAnswer;
}