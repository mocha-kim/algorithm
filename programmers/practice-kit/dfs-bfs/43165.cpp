#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int sum, int cur, vector<int> &numbers, int target)
{
	if (cur == numbers.size())
	{
		if (sum == target)
			answer++;
		return;
	}

	sum += numbers[cur];
	dfs(sum, cur + 1, numbers, target);
	sum -= 2 * numbers[cur];
	dfs(sum, cur + 1, numbers, target);
}

int solution(vector<int> numbers, int target)
{
	dfs(0, 0, numbers, target);
    return answer;
}