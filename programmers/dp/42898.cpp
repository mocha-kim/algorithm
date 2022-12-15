#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int> > map(n + 1, vector<int>(m + 1, 0));
    for (auto p : puddles) 
        map[p[1]][p[0]] = -1;
    
    map[1][1] = 1;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            if (map[y][x] == -1)
                continue;
            if (map[y][x - 1] != -1)
                map[y][x] += map[y][x - 1];
            if (map[y - 1][x] != -1)
                map[y][x] += map[y - 1][x];
            map[y][x] %= 1000000007;
        }
    }
    return map[n][m];
}