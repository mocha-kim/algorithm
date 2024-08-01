#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<vector<pair<int, int>>> graph(v);
    {
        int a, b, c;
        for(int i = 0; i < e; i++) {
            cin >> a >> b >> c;
            graph[a - 1].push_back({ c, b - 1 });
            graph[b - 1].push_back({ c, a - 1 });
        }
    }

    int total_weight = 0;
    vector<bool> is_visited(v, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, 0 });
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if (is_visited[cur])
            continue;

        total_weight += cur_weight;
        is_visited[cur] = true;
        for (pair<int, int> p : graph[cur]) {
            int next = p.second;
            int next_weight = p.first;
            if (is_visited[next])
                continue;
            pq.push({ next_weight, next });
        }
    }

    cout << total_weight;
    return 0;
}