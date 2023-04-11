#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = -1;
    int total_rounds = enemy.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < total_rounds; i++) {
        pq.push(enemy[i]);
        if (pq.size() > k) {
            n -= pq.top();
            pq.pop();
        }
        if (n < 0)
            return i;
    }
    return total_rounds;
}