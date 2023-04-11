#include <string>
#include <vector>

using namespace std;

void dfs(int cur, int n, vector<bool> &checked, vector<vector<int> > &computers)
{
    checked[cur] = true;
    for (int i = 0; i < n; i++)
    {
        if (computers[cur][i] == 1 && !checked[i])
            dfs(i, n, checked, computers);
    }
}

int solution(int n, vector<vector<int> > computers)
{
    int answer = 0;
    vector<bool> checked(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!checked[i])
        {
            dfs(i, n, checked, computers);
            answer++;
        }
    }
    return answer;
}