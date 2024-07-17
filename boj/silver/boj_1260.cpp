#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int cur, vector<vector<bool>> &graph, vector<bool> &is_visited, vector<int> &visited_node);
void bfs(int start, vector<vector<bool>> &graph, vector<bool> &is_visited);

int g_n, g_m;
	
int main() {
	int v;
	cin >> g_n >> g_m >> v;
	
	vector<vector<bool>> graph(g_n, vector<bool>(g_n, false));
	for (int i = 0; i < g_m; i++)
	{
		int start, end;
		cin >> start >> end;
		graph[start - 1][end - 1] = true;
		graph[end - 1][start - 1] = true;
	}
	
	vector<bool> is_visited(g_n, false);
	
	vector<int> visited_node;
	dfs(v - 1, graph, is_visited, visited_node);
    for (int i = 0; i < visited_node.size(); ++i) {
        cout << visited_node[i] + 1;
        if (i != visited_node.size() - 1) {
            cout << " ";
        }
    }
	cout << "\n";

	for (int i = 0; i < is_visited.size(); i++)
		is_visited[i] = false;
	bfs(v - 1, graph, is_visited);
    return 0;
}

void dfs(int cur, vector<vector<bool>> &graph, vector<bool> &is_visited, vector<int> &visited_node) {
	is_visited[cur] = true;
	visited_node.push_back(cur);
	for (int i = 0; i < graph.size(); i++)
	{
		if (!graph[cur][i] || is_visited[i])
			continue;
		dfs(i, graph, is_visited, visited_node);
	}
}

void bfs(int start, vector<vector<bool>> &graph, vector<bool> &is_visited) {
	vector<int> visited_node;
	queue<int> q;
	q.push(start);
	is_visited[start] = true;
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		visited_node.push_back(cur);
		for (int i = 0; i < graph.size(); i++)
		{
			if (!graph[cur][i] || is_visited[i])
				continue;
			q.push(i);
			is_visited[i] = true;
		}
	}
	
    for (int i = 0; i < visited_node.size(); ++i) {
        cout << visited_node[i] + 1;
        if (i != visited_node.size() - 1) {
            cout << " ";
        }
    }
}