#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations)
{
	map<int, int> nums;
	priority_queue<int, vector<int>, less<int> > max;
	priority_queue<int, vector<int>, greater<int> > min;

	for (string s : operations)
	{
		if (s[0] == 'I')
		{
			int num = stoi(s.substr(1));
			nums[num]++;
			min.push(num);
			max.push(num);
		}
		else if (s[0] == 'D')
		{
			if (s[2] == '-' && !min.empty())
			{
				int min_num = min.top();
				while (nums[min_num] < 1)
				{
					if (min.empty())
						break;
					min_num = min.top();
					min.pop();
				}
				if (!min.empty())
				{
					nums[min_num]--;
					min.pop();
				}
			}
			else if (!max.empty())
			{
				int max_num = max.top();
				while (nums[max_num] < 1)
				{
					if (max.empty())
						break;
					max_num = max.top();
					max.pop();
				}
				if (!max.empty())
				{
					nums[max_num]--;
					max.pop();
				}
			}
		}
	}
    vector<int> answer(2);
	if (min.empty() || max.empty())
		return answer;
		
	int max_num = max.top();
	while (nums[max_num] < 1)
	{
		if (max.empty())
			break;
		max_num = max.top();
		max.pop();
	}
	int min_num = min.top();
	while (nums[min_num] < 1)
	{
		if (min.empty())
			break;
		min_num = min.top();
		min.pop();
	}
	answer[0] = max_num;
	answer[1] = min_num;
    return answer;
}