#include <iostream>
#include <queue>
using namespace std;

void dfs(int cur, vector<vector<int>>& graph, vector<int>& parent);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;
    vector<vector<int>> graph(n);
    {
        int a, b;
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            graph[a - 1].emplace_back(b - 1);
            graph[b - 1].emplace_back(a - 1);
        }
    }

    vector<int> parent(n, -1);
    parent[0] = 0;

    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : graph[cur]) {
            if (parent[next] != -1)
                continue;
            parent[next] = cur;
            q.push(next);
        }
    }
    
    for (int i = 1; i < n; i++)
        cout << parent[i] + 1 << "\n";
}