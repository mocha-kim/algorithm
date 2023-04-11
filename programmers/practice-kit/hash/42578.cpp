#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    map<string, int> count;
    
    for (int i = 0; i < clothes.size(); i++)
        count[clothes[i][1]]++;
    
    int answer = 1;
    for (auto i : count)
        answer *= i.second + 1;
    answer--;
    
    return answer;
}