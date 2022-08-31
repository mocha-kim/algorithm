#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer(2);
	int tile_count = brown + yellow;
	for (int h = 2; h * h <= tile_count; h++)
	{
		if ((tile_count % h) == 0)
		{
			int w = tile_count / h;
			int border = w * 2 + h * 2 - 4;
			if (border == brown && (tile_count - border) == yellow)
			{
				answer[0] = w;
				answer[1] = h;
				break;
			}
		}
	}
    return answer;
}