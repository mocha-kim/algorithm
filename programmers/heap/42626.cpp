#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{    
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    int first, second, answer = 0;
    while (pq.size() > 1 && pq.top() < K)
    {
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        pq.push(first + second * 2);
        answer++;
    }
    if (pq.top() < K)
        answer = -1;
    
    return answer;
}