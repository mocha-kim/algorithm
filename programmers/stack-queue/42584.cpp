#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    int size = prices.size();
    vector<int> answer(size);
    stack<int> reds;
    for (int i = 0; i < size; i++)
    {
        while (!reds.empty())
        {
            if (prices[reds.top()] > prices[i])
            {
                answer[reds.top()] = i - reds.top();
                reds.pop();
            }
            else
                break;
        }
        reds.push(i);
    }
    while (!reds.empty())
    {
        answer[reds.top()] = size - reds.top() - 1;
        reds.pop();
    }
    return answer;
}