#include <string>
#include <vector>

using namespace std;

long long answer = 0;

void dfs(vector<long long> &weights, vector<vector<int>> &tree, int cur, int parent)
{
    for (int i = 0; i < tree[cur].size(); i++)
    {
        if (tree[cur][i] != parent)
            dfs(weights, tree, tree[cur][i], cur);
    }
    
    answer += abs(weights[cur]);
    weights[parent] += weights[cur];
}

long long solution(vector<int> a, vector<vector<int>> edges)
{
    vector<long long> weights(a.size());
    for (int i = 0; i < a.size(); i++)
        weights[i] = a[i];
    
    vector<vector<int>> tree(a.size());
    for (int i = 0; i < edges.size(); i++)
    {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(weights, tree, 0, 0);
    if (weights[0] != 0)
        return -1;
    return answer;
}