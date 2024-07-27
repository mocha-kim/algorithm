#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 200001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e, start;
    cin >> v >> e >> start;
    start--;

    vector<vector<pair<int, int>>> graph(v);
    {
        int begin, end, weight;
        for (int i = 0; i < e; i++) {
            cin >> begin >> end >> weight;
            graph[begin - 1].push_back({ weight, end - 1 });
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> min(v, INF);
    min[start] = 0;
    pq.push({ 0, start });
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        for (pair<int, int> p : graph[cur]) {
            int next = p.second;
            int next_dist = cur_dist + p.first;
            if (min[next] < next_dist)
                continue;
            min[next] = next_dist;
            pq.push({ next_dist, next });
        }
    }
    for (int i = 0; i < v; i++) {
        if (min[i] == INF)
            cout << "INF\n";
        else
            cout << min[i] << "\n";
    }
    return 0;
}