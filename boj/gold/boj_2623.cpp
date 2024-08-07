#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    {
        int count, cur, next;
        for (int i = 0; i < m; i++) {
            cin >> count >> cur;
            cur--;
            for (int j = 1; j < count; j++) {
                cin >> next;
                next--;
                graph[cur].push_back(next);
                indegree[next]++;
                cur = next;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> sorted;
    sorted.reserve(n);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        sorted.push_back(cur + 1);

        for (int next : graph[cur]) {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    if (sorted.size() != n)
        cout << "0\n";
    else
        for (int num : sorted)
            cout << num << "\n";
            
    return 0;
}