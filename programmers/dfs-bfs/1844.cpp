#include <vector>
#include <queue>
using namespace std;

#define WALL 0
#define EMPTY 1

int solution(vector<vector<int> > maps)
{
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int height = maps.size();
    int width = maps[0].size();
    
    int x, y, next_x, next_y;
    
    vector<vector<int> > dist(height, vector<int>(width, -1));
    dist[0][0] = 1;
    
    queue<pair<int, int> > path;
    path.push({0, 0});
    
    while (path.size())
    {
        x = path.front().first;
        y = path.front().second;
        path.pop();
        
        if (x == width - 1 && y == height - 1)
            return dist[y][x];
        
        for (int i = 0; i < 4; i++)
        {
            next_x = x + dir[i][0];
            next_y = y + dir[i][1];
            
            if (next_x >= 0 && next_x < width && next_y >= 0 && next_y < height)
            {
                if (maps[next_y][next_x] == EMPTY && dist[next_y][next_x] == -1)
                {
                    dist[next_y][next_x] = dist[y][x] + 1;
                    path.push({next_x, next_y});
                }
            }
        }
    }
    return -1;
}