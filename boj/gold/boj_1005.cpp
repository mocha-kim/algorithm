#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, k;
        cin >> n >> k;

        vector<int> time(n + 1);
        vector<int> total_time(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> time[i];
            total_time[i] = time[i];
        }
        
        int x, y;
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            graph[x].emplace_back(y);
            indegree[y]++;
        }

        int w;
        cin >> w;

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : graph[cur]) {
                total_time[next] = max(total_time[next], total_time[cur] + time[next]);
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        cout << total_time[w] << "\n";
    }
    return 0;
}