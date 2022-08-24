#include <string>
#include <vector>

using namespace std;

#define MAX 99999

enum Type
{
	AlpReq,
	CopReq,
	AlpRwd,
	CopRwd,
	Cost
};

int solution(int alp, int cop, vector<vector<int> > problems)
{
	int max_alp = -1, max_cop = -1;
	for (auto p : problems)
	{
		max_alp = max(p[AlpReq], max_alp);
		max_cop = max(p[CopReq], max_cop);
	}
	if (alp >= max_alp && cop >= max_cop)
		return 0;
	int min_alp = min(alp, max_alp);
	int min_cop = min(cop, max_cop);
	vector<vector<int> > dp(152, vector<int>(152, MAX));
	dp[alp][cop] = 0;
	for (int i = min_alp; i <= max_alp; i++)
	{
		for (int j = min_cop; j <= max_cop; j++)
		{
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			for (auto p : problems)
				if (i >= p[AlpReq] && j >= p[CopReq]
				&& (i + p[AlpRwd] < 151) && (j + p[CopRwd] < 151))
					dp[i + p[AlpRwd]][j + p[CopRwd]] = min(dp[i + p[AlpRwd]][j + p[CopRwd]], dp[i][j] + p[Cost]);
		}
	}
    return dp[max_alp][max_cop];
}