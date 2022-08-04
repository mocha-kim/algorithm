#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct s_print
{
    int index;
    int priority;
    
    s_print(int i, int p) : index(i), priority(p) {}
} t_print;

int get_max_priority(vector<int> &v)
{
	for (int i = v.size() - 1; i >= 0; i--)
		if (v[i] > 0)
			return i;
	return 0;
}

int solution(vector<int> priorities, int location)
{
    queue<t_print> list;
	vector<int> counts(9);
	int max = 0;
    for (int i = 0; i < priorities.size(); i++)
    {
        t_print tmp(i, priorities[i]);
        list.push(tmp);
		counts[tmp.priority]++;
		if (max < tmp.priority)
			max = tmp.priority;
    }
    int answer = 1;
    while (!list.empty())
    {
        t_print tmp = list.front();
        list.pop();
        if (max > tmp.priority)
            list.push(tmp);
        else
        {
            if (tmp.index == location)
                break;
            answer++;
			counts[tmp.priority]--;
			if (counts[tmp.priority] == 0)
				max = get_max_priority(counts);
        }
    }
    return answer;
}