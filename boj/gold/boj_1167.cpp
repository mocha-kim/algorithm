#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int g_max_dist;
int g_max_node;
bool g_is_visited[100000];

void dfs(int cur, int dist, vector<vector<pair<int, int>>>& graph);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin >> v;
    int from, to, dist;
    vector<vector<pair<int, int>>> graph(v);
    for (int i = 0; i < v; i++) {
        cin >> from >> to;
        while(to != -1) {
            cin >> dist;
            graph[from - 1].push_back({to - 1, dist});
            graph[to - 1].push_back({from - 1, dist});
            cin >> to;
        }
    }

    g_max_dist = 0;
    memset(g_is_visited, false, sizeof(g_is_visited));
    dfs(0, 0, graph);

    g_max_dist = 0;
    memset(g_is_visited, false, sizeof(g_is_visited));
    dfs(g_max_node, 0, graph);

    cout << g_max_dist;
    return 0;
}

void dfs(int cur, int dist, vector<vector<pair<int, int>>>& graph) {
    if (g_max_dist < dist) {
        g_max_dist = dist;
        g_max_node = cur;
    }
    g_is_visited[cur] = true;
    for (pair<int, int> p : graph[cur]) {
        int next = p.first;
        if (g_is_visited[next])
            continue;
        dfs(next, dist + p.second, graph);
    }
}