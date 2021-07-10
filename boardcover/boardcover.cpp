#include <stdio.h>
#include <string.h>

int board[20][20];
int W, H;
int block[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} }
};

int coverBoard();
void findStart(int *x, int *y);
bool blockSpace(int x, int y, int block, int mode);

int main()
{
	int testN;
	char tmp;

	scanf("%d\n", &testN);
	for (int i = 0; i < testN; i++)
	{
		scanf("%d %d\n", &W, &H);
		for (int j = 0; j < W; j++)
			for (int k = 0; k < H; k++)
			{
				scanf("%c ", &tmp);
				if (tmp == '.')
					board[j][k] = 0;
				else if (tmp == '#')
					board[j][k] = 1;
			}
		for (int j = 0; j < W; j++)
		{
			for (int k = 0; k < H; k++)
			{
				printf("%d", board[j][k]);
			}
			printf("\n");
		}
		printf("%d\n", coverBoard());
	}
}

int coverBoard()
{
	int x = -1, y = -1;
	int count = 0;

	findStart(&x, &y);
	if (x == -1) return 1;

	for (int shape = 0; shape < 4; shape++)
	{
		if (blockSpace(x, y, shape, 1))
			count += coverBoard();
		blockSpace(x, y, shape, -1);
	}
	return count;
}

void findStart(int *x, int *y)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == 0)
			{
				*x = j;
				*y = i;
				return;
			}
		}
	}
}

bool blockSpace(int x, int y, int shape, int mode)
{
	int nextX, nextY;

	for (int i = 0; i < 3; i++)
	{
		nextX = x + block[shape][i][1];
		nextY = y + block[shape][i][0];
		if (nextX < 0 || nextX >= W || nextY < 0 || nextY >= H)
			return false;
		else if ((board[nextY][nextX] += mode) > 1)
			return false;
	}
	return true;
}