#include <stdio.h>
#include <string.h>

int stdtN;
bool paired[10];
bool friends[10][10];

int countPair();

int main()
{
	int testN;
	int pairN;
	int pair[2];

	scanf("%d", &testN);
	for (int i = 0; i < testN; i++)
	{
		memset(friends, false, sizeof(friends));
		memset(paired, false, sizeof(paired));
		scanf("%d%d", &stdtN, &pairN);
		for (int j = 0; j < pairN; j++)
		{
			scanf("%d%d", &pair[0], &pair[1]);
			friends[pair[0]][pair[1]] = true;
			friends[pair[1]][pair[0]] = true;
		}
		printf("%d\n", countPair());
	}
}

int countPair()
{
	int count = 0;
	int curStd = -1;

	for (int i = 0; i < stdtN; i++)
	{
		if (!paired[i])
		{
			curStd = i;
			break ;
		}
	}
	if (curStd == -1)
		return 1;
	
	for (int i = curStd + 1; i < stdtN; i++)
	{
		if (!paired[i] && friends[curStd][i])
		{
			paired[curStd] = true;
			paired[i] = true;
			count += countPair();
			paired[curStd] = false;
			paired[i] = false;
		}
	}
	return count;
}