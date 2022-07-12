#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define SHEEP 0
#define WOLF 1
#define EMPTY 2

using namespace std;

int g_max_sheep = 0;
bool g_visit[20][20][20];

struct s_info
{
	bool is_sheep;
    int state;
	vector<int> linked_node;
};

void dfs(int sheep_num, int wolf_num, unordered_map<int, struct s_info> &info, int cur)
{
    if (cur == 0)
        g_max_sheep = max(g_max_sheep, sheep_num);
    
    for (int next : info[cur].linked_node)
    {
        switch(info[next].state)
        {
            case SHEEP:
                if (!g_visit[next][sheep_num + 1][wolf_num])
                {
                    g_visit[next][sheep_num + 1][wolf_num] = true;
                    info[next].state = EMPTY;
                    dfs(sheep_num + 1, wolf_num, info, next);
                    g_visit[next][sheep_num + 1][wolf_num] = false;
                    info[next].state = SHEEP;
                }
                break;
            case WOLF:
                if (!g_visit[next][sheep_num][wolf_num + 1] && sheep_num > wolf_num + 1)
                {
                    g_visit[next][sheep_num][wolf_num + 1] = true;
                    info[next].state = EMPTY;
                    dfs(sheep_num, wolf_num + 1, info, next);
                    g_visit[next][sheep_num][wolf_num + 1] = false;
                    info[next].state = WOLF;
                }
                break;
            case EMPTY:
                if (!g_visit[next][sheep_num][wolf_num])
                {
                    g_visit[next][sheep_num][wolf_num] = true;
                    dfs(sheep_num, wolf_num, info, next);
                    g_visit[next][sheep_num][wolf_num] = false;
                }
                break;
            default:
                break;
        }
    }
}

int solution(vector<int> info, vector< vector<int> > edges)
{
	unordered_map<int, struct s_info> node_info;

	for (int i = 0; i < info.size(); i++)
	{
		struct s_info tmp;
		tmp.is_sheep = info[i] == 0 ? true : false;
		tmp.state = info[i] == 0 ? SHEEP : WOLF;
        node_info[i] = tmp;
	}

	for (auto v : edges)
    {
		node_info[v[0]].linked_node.push_back(v[1]);
		node_info[v[1]].linked_node.push_back(v[0]);
    }

    node_info[0].state = EMPTY;
    g_visit[0][1][0] = true;
	dfs(1, 0, node_info, 0);

    return g_max_sheep;
}