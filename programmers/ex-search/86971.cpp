#include <string>
#include <vector>
#include <queue>

using namespace std;

int g_n;

int count_wire(int start, vector<vector<bool> > &graph)
{
	int count = 0;
	vector<bool> is_visited(g_n);
	is_visited[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g_n; i++)
		{
			if (graph[cur][i] > 0 && !is_visited[i])
			{
				q.push(i);
				is_visited[i] = true;
				count++;
			}
		}
	}
	return count;
}

int solution(int n, vector<vector<int> > wires)
{
	g_n = n;
	vector<vector<bool> > graph(n, vector<bool>(n, false));
	for (vector<int> wire : wires)
	{
		graph[wire[0] - 1][wire[1] - 1] = true;
		graph[wire[1] - 1][wire[0] - 1] = true;
	}

	int answer = 99999;
	for (vector<int> wire : wires)
	{
		int v1 = wire[0] - 1;
		int v2 = wire[1] - 1;
		graph[v1][v2] = graph[v2][v1] = false;

		int gap = abs(count_wire(v1, graph) - count_wire(v2, graph));
		answer = min(gap, answer);
		graph[v1][v2] = graph[v2][v1] = true;
	}
    return answer;
}