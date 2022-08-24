#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
	long long sum1 = 0, sum2 = 0;
	queue<int> q1, q2;
	for (int i : queue1)
	{
		sum1 += i;
		q1.push(i);
	}
	for (int i : queue2)
	{
		sum2 += i;
		q2.push(i);
	}
	int answer = 0;
	int total_size = queue1.size() + queue2.size();
	for (int i = 0; i < 2 * total_size + 1; i++)
	{
		if (sum1 > sum2)
		{
			int tmp = q1.front();
			q1.pop();
			q2.push(tmp);
			sum1 -= tmp;
			sum2 += tmp;
		}
		else if (sum1 < sum2)
		{
			int tmp = q2.front();
			q2.pop();
			q1.push(tmp);
			sum1 += tmp;
			sum2 -= tmp;
		}
        else
			return answer;
		answer++;
	}
	return -1;
}