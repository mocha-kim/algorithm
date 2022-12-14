#include <string>
#include <vector>

#define MAX 9999

using namespace std;

enum Type : int
{
	shelter,
	gate,
	summit
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<vector<int> > graph(n + 1, vector<int>(n + 1, MAX));
	vector<int> graph_info(n + 1, Type::shelter);
	for (int gate : gates)
		graph_info[gate] = Type::gate;
	for (int summit : summits)
		graph_info[summit] = Type::summit;
	for (auto path : paths)
	{
		graph[path[0]][path[1]] = path[2];
		if (graph_info[path[0]] != Type::gate)
			graph[path[1]][path[0]] = path[2];
	}

	bool summit_visited = false;


	vector<int> answer(2);
    return answer;
}