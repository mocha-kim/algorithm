#include <string>
#include <vector>

using namespace std;

int g_answer = -1;
int g_size;

void dfs(int k, int cur, vector<int> visited, vector<vector<int> > &dungeons)
{
    if (g_answer < cur)
        g_answer = cur;

    for (int i = 0; i < g_size; i++)
    {
        if (!visited[i] && dungeons[i][0] <= k)
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], cur + 1, visited, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    g_size = dungeons.size();
    vector<int> visited(g_size);
    dfs(k, 0, visited, dungeons);
    return g_answer;
}