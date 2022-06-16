#include <stdio.h>
#include <string.h>

int board[20][20];
int W, H;
int block[4][3][2] = {
	{ {0, 0}, {0, 1}, {1, 0} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {1, -1} }
};
int ret;

int coverBoard();

int main()
{
	int testN;
	char tmp;

	scanf("%d\n", &testN);
	for (int i = 0; i < testN; i++)
	{
		ret = 0;
		scanf("%d %d\n", &W, &H);
		for (int j = 0; j < W; j++)
		{
			for (int k = 0; k < H; k++)
			{
				scanf("%c ", &tmp);
				if (tmp == '.')
					board[j][k] = 0;
				else if (tmp == '#')
					board[j][k] = 1;
			}
		}
		coverBoard();
		printf("%d\n", ret);
	}
}

int coverBoard()
{
	int x = -1;
	int y = -1;

	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (board[i][j] == 0)
			{
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1) break;
	}

	if (x == -1)
	{
		ret++;
		return ret;
	}

	int x1, x2, y1, y2;
	for (int i = 0; i < 4; i++)
	{
		x1 = x + block[i][1][0];
		y1 = y + block[i][1][1];
		x2 = x + block[i][2][0];
		y2 = y + block[i][2][1];

		if (x1 < 0 || x1 >= W || x2 < 0 || x2 >= W
			|| y1 < 0 || y1 >= H || y2 < 0 || y2 >= H) continue;
		
		if (!(board[x1][y1] || board[x2][y2]))
		{
			board[x][y] = 1;
			board[x1][y1] = 1;
			board[x2][y2] = 1;
			coverBoard();
			board[x][y] = 0;
			board[x1][y1] = 0;
			board[x2][y2] = 0;
		}
	}
	return (ret);
}