#include <iostream>
#include <vector>
using namespace std;

int g_n;
void check_connection(int cur, vector<vector<bool>> &graph, vector<bool> &is_visited);

int main() {
    int m;
    cin >> g_n >> m;

    int start, end;
    vector<vector<bool>> graph(g_n, vector<bool>(g_n, false));
    for (int i = 0; i < m; i++) {
        cin >> start >> end;
        graph[start - 1][end - 1] = true;
        graph[end - 1][start - 1] = true;
    }

    int count = 0;
    vector<bool> is_visited(g_n, false);
    for (int i = 0; i < g_n; i++) {
        if (is_visited[i])
            continue;
        check_connection(i, graph, is_visited);
        count++;
    }
    cout << count;
}

void check_connection(int cur, vector<vector<bool>> &graph, vector<bool> &is_visited) {
    is_visited[cur] = true;
    for (int i = 0; i < g_n; i++) {
        if (is_visited[i] || !graph[cur][i])
            continue;
        check_connection(i, graph, is_visited);
    }
}