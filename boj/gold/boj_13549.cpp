#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

struct compare {
    bool operator() (const pair<int, int>& p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<bool> is_visited(MAX, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ n, 0 });
    while(!pq.empty()) {
        int time = pq.top().second;
        int cur = pq.top().first;
        pq.pop();
        is_visited[cur] = true;

        if (cur == k) {
            cout << time;
            break;
        }

        int next = cur + 1;
        if (next < MAX && !is_visited[next])
            pq.push({ next, time + 1 });
        next = cur - 1;
        if (next >= 0 && !is_visited[next])
            pq.push({ next, time + 1 });
        next = cur * 2;
        if (next < MAX && !is_visited[next])
            pq.push({ next, time });
    }

    return 0;
}