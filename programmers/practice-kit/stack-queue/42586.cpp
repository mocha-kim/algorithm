#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> days;
    for (int i = 0; i < progresses.size(); i++)
    {
        int div = (100 - progresses[i]) / speeds[i];
        int rem = (100 - progresses[i]) % speeds[i];
        days.push(div + (rem == 0 ? 0 : 1));
    }
    
    int progress = days.front();
    int count = 1;
    days.pop();
    while (!days.empty())
    {
        if (days.front() <= progress)
        {
            days.pop();
            count++;
        }
        else
        {
            progress = days.front();
            days.pop();
            answer.push_back(count);
            count = 1;
        }
    }
    if (count != 0)
        answer.push_back(count);
    
    return answer;
}