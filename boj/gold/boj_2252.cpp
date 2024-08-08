#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    {
        int a, b;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a - 1].push_back(b - 1);
            indegree[b - 1]++;
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

    for (int num : sorted)
        cout << num << " ";
    return 0;
}