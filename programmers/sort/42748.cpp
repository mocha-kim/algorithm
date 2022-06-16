#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector< vector<int> > commands)
{
    vector<int> answer;
    
    for (int idx = 0; idx < commands.size(); idx++)
    {
        if (commands[idx][0] == commands[idx][1])
        {
            answer.push_back(array[commands[idx][0] - 1]);
            continue;
        }
            
        vector<int> tmp(array);
        for (int i = 0; i < array.size() - commands[idx][1]; i++)
            tmp.pop_back();
        for (int i = 1; i < commands[idx][0]; i++)
            tmp.erase(tmp.begin());
        
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[commands[idx][2] - 1]);
    }
    
    return answer;
}