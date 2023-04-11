#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int max_width = 0, max_height = 0;
    for (auto size : sizes)
    {
        int width = max(size[0], size[1]);
        int height = min(size[0], size[1]);
        if (max_width < width)
            max_width = width;
        if (max_height < height)
            max_height = height;
    }
    return max_width * max_height;
}