#include <iostream>
#include <queue>
using namespace std;

struct compare {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    int start, end, cost;
    vector<vector<pair<int, int>>> graph(n); 
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> cost;
        graph[start - 1].emplace_back(end - 1, cost);
    }
    cin >> start >> end;
    start--;
    end--;

    vector<int> min_cost(n, 100000000);
    min_cost[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ start, min_cost[start] });

    while(!pq.empty()) {
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if (min_cost[cur] < cost)
            continue;

        for (const pair<int, int>& neighbor : graph[cur]) {
            int next = neighbor.first;
            int next_cost = cost + neighbor.second;
            if (next_cost < min_cost[next]) {
                pq.push({next, next_cost});
                min_cost[next] = next_cost;
            }
        }
    }

    cout << min_cost[end];
    return 0;
}