#include <iostream>
#include <vector>
using namespace std;

int g_max_node;
int g_max_distance;
vector<vector<pair<int, int>>> g_graph;
vector<bool> g_is_visited;

void dfs(int cur, int weight);

int main() {
    int n;
    cin >> n;

    g_graph.resize(n);
    {
        int p, c, w;
        for (int i = 0; i < n - 1; i++) {
            cin >> p >> c >> w;
            g_graph[p - 1].push_back({ c - 1, w });
            g_graph[c - 1].push_back({ p - 1, w });
        }
    }

    g_max_distance = -1;
    g_is_visited.resize(n);
    fill(g_is_visited.begin(), g_is_visited.end(), false);
    dfs(0, 0);

    g_max_distance = -1;
    fill(g_is_visited.begin(), g_is_visited.end(), false);
    dfs(g_max_node, 0);
    cout << g_max_distance;
}

void dfs(int cur, int weight) {
    g_is_visited[cur] = true;
    if (weight > g_max_distance) {
        g_max_distance = weight;
        g_max_node = cur;
    }
    for (pair<int, int> p : g_graph[cur]) {
        if (g_is_visited[p.first])
            continue;
        dfs(p.first, weight + p.second);
    }
}