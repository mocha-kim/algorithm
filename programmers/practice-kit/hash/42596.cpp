#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    
    unordered_map<string, int> map;
    
    for (string runner : participant)
        map[runner]++;
    
    for (string runner : completion)
        map[runner]--;
    
    for (auto tmp : map)
    {
        if (tmp.second == 1)
            return tmp.first;
    }
}