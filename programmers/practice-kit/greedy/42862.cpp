#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    vector<int> counts(n, 1);
    
    for (int i = 0; i < lost.size(); i++)
        counts[lost[i] - 1]--;
    for (int i = 0; i < reserve.size(); i++)
        counts[reserve[i] - 1]++;
    
    for (int i = 0; i < n; i++)
    {
        if (counts[i] == 0)
        {
            if (i >= 1 && counts[i - 1] == 2)
            {
                counts[i - 1]--;
                counts[i]++;
            }
            else if (i <= n - 1 && counts[i + 1] == 2)
            {
                counts[i + 1]--;
                counts[i]++;
            }
        }
    }
    
    return count_if(counts.begin(), counts.end(), [](int v) { return v > 0; });
}