#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end(), greater<int>());
    int max = 0;
    int i = citations.size() / 2 - 1;
    while (i >= 0 && i < citations.size())
    {
        if (citations[i] < i + 1)
            i--;
        else
        {
            if (max == i + 1)
                break;
            if (max < i + 1)
                max = i + 1;
            i++;
        }
    }
    return max;
}