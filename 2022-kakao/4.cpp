#include <string>
#include <vector>

#define SCORE_RANGE 11

using namespace std;

vector<int> g_answer;
int bigest_gap = 0;

void save_answer(vector<int> &info, vector<int> &ryan_info)
{
	int apeach = 0;
	int ryan = 0;

	for (int i = 0; i < SCORE_RANGE; i++)
	{
		if (info[i] == 0 && ryan_info[i] == 0)
			continue;

		if (info[i] >= ryan_info[i])
			apeach += SCORE_RANGE - 1 - i;
		else
			ryan += SCORE_RANGE - 1 - i;
	}

	if (ryan > apeach && ryan - apeach >= bigest_gap)
	{
		if (g_answer.size() == 0 || ryan - apeach > bigest_gap)
		{
			g_answer = ryan_info;
			bigest_gap = ryan - apeach;
			return;
		}

		for (int i = SCORE_RANGE - 1; i >= 0; i--)
		{
			if (g_answer[i] > ryan_info[i])
				return;
			else if (g_answer[i] < ryan_info[i])
			{
				g_answer = ryan_info;
				bigest_gap = ryan - apeach;
				return;
			}
		}
	}
}

void find_answer(int left_arrow, vector<int> &info, vector<int> &ryan_info, int cur)
{
	if (cur == SCORE_RANGE || left_arrow == 0)
	{
		if (left_arrow > 0)
			ryan_info[SCORE_RANGE - 1] = left_arrow;
		save_answer(info, ryan_info);
		if (left_arrow > 0)
			ryan_info[SCORE_RANGE - 1] = 0;
		return;
	}
	
	if (left_arrow >= info[cur] + 1)
	{
		ryan_info[cur] = info[cur] + 1;
		find_answer(left_arrow - (info[cur] + 1), info, ryan_info, cur + 1);
	}
	
	ryan_info[cur] = 0;
	find_answer(left_arrow, info, ryan_info, cur + 1);
}

vector<int> solution(int n, vector<int> info)
{
	vector<int> ryan_info(SCORE_RANGE, 0);

	find_answer(n, info, ryan_info, 0);
	
	if (g_answer.size() == 0)
		g_answer.push_back(-1);

    return g_answer;
}