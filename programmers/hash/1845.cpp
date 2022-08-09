#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> ponketmons;
    for (int i : nums)
        ponketmons[i]++;
    
    int answer = min(nums.size() / 2, ponketmons.size());
    return answer;
}