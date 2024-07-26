#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 100001

struct compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    int begin, end, time;
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<pair<int, int>>> reverse_graph(n);
    for (int i = 0; i < m; i++) {
        cin >> begin >> end >> time;
        graph[begin - 1].push_back({ end - 1, time });
        reverse_graph[end - 1].push_back({ begin - 1, time });
    }

    vector<int> min_time_to_x = dijkstra(x - 1, n, reverse_graph);
    vector<int> min_time_from_x = dijkstra(x - 1, n, graph);

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (i != x - 1) {
            int round_trip_time = min_time_to_x[i] + min_time_from_x[i];
            if (round_trip_time < INF)
                answer = max(answer, round_trip_time);
        }
    }
    cout << answer;
    return 0;
}

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph) {
    vector<int> min_time(n, INF);
    min_time[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({ start, 0 });
    while(!pq.empty()) {
        int cur_idx = pq.top().first;
        int cur_time = pq.top().second;
        pq.pop();

        if (cur_time > min_time[cur_idx]) 
            continue;
        
        for (pair<int, int> next : graph[cur_idx]) {
            int next_idx = next.first;
            int next_time = cur_time + next.second;;
            if (next_time < min_time[next_idx]) {
                min_time[next_idx] = next_time;
                pq.push({ next_idx, next_time });
            }
        }
    }
    return min_time;
}