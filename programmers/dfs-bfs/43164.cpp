#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int g_size;
bool g_is_found = false;

void dfs(string cur, int visit_count, unordered_map<string, map<string, int> > &infos, vector<string> &answer)
{
	answer.push_back(cur);
	if (visit_count == g_size)
	{
		g_is_found = true;
		return;
	}

	for (auto i = infos[cur].begin(); i != infos[cur].end(); i++)
	{
		if ((*i).second > 0)
		{
            (*i).second--;
			dfs((*i).first, visit_count + 1, infos, answer);
			if (g_is_found)
				return;
			(*i).second++;
		}
	}
	answer.pop_back();
}

vector<string> solution(vector<vector<string> > tickets)
{
	unordered_map<string, map<string, int> > infos;
	for (vector<string> ticket : tickets)
		infos[ticket[0]][ticket[1]]++;
	g_size = tickets.size();
	vector<string> answer;
	dfs("ICN", 0, infos, answer);
    return answer;
}