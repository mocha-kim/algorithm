#include <iostream>
#include <vector>
using namespace std;

int g_n;
int g_count = -1;

void dfs(int cur, vector<vector<bool>> &graph, vector<bool> &is_visited);

int main() {
    int k;
    cin >> g_n >> k;

    int a, b;
    vector<vector<bool>> graph(g_n, vector<bool>(g_n, false));
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        graph[a - 1][b - 1] = true;
        graph[b - 1][a - 1] = true;
    }

    vector<bool> is_visited(g_n, false);
    dfs(0, graph, is_visited);
    cout << g_count;
    return 0;
}

void dfs(int cur, vector<vector<bool>> &graph, vector<bool> &is_visited) {
    g_count++;
    is_visited[cur] = true;

    for (int next = 0; next < g_n; next++) {
        if (is_visited[next] || !graph[cur][next])
            continue;
        dfs(next, graph, is_visited);
    }
}