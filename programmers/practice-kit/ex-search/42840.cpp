#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
     
    vector<int> counts = {0, 0, 0};
    vector<int> helper1 = {1, 2, 3, 4, 5};
    vector<int> helper2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> helper3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == helper1[i % helper1.size()])
            counts[0]++;
        if (answers[i] == helper2[i % helper2.size()])
            counts[1]++;
        if (answers[i] == helper3[i % helper3.size()])
            counts[2]++;
    }
    
    int max = *max_element(counts.begin(), counts.end());
    for (int i = 0; i < 3; i++)
        if (max <= counts[i])
            answer.push_back(i + 1);
    
    return answer;
}