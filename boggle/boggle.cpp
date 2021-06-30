#include <stdio.h>
#include <string.h>

char board[5][5];
char cache[5][5][10];
char word[11];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool findWord();
bool findNext(int x, int y, int i);

int main()
{
	int testN;
	int wordN;

	scanf("%d", &testN);
	for (int i = 0; i < testN; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf("%s", board[j]);
		scanf("%d", &wordN);
		for (int j= 0; j < wordN; j++)
		{
			memset(cache, true, sizeof(cache));
			scanf("%s", word);
			if (findWord())
				printf("%s YES\n", word);
			else
				printf("%s NO\n", word);
		}
	}
}

bool findWord()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
			if (board[y][x] == word[0])
				if (findNext(x, y, 0))
					return (true);
	}
	return false;
}

bool findNext(int x, int y, int i)
{
	int nextIdx = i + 1;
	int nextX, nextY;

	if (nextIdx >= strlen(word))
		return true;
	
	for (int dir = 0; dir < 8; dir++)
	{
		nextX = x + dx[dir];
		nextY = y + dy[dir];
		if ((nextX >= 0) && (nextX < 5) && (nextY >= 0) && (nextY < 5))
			if (cache[nextY][nextX][nextIdx] && (word[nextIdx] == board[nextY][nextX]))
					if (findNext(nextX, nextY, nextIdx))
						return true;
	}
	cache[y][x][i] = false;
	return false;
}
