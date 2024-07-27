#include <iostream>
#include <vector>
using namespace std;

#define INF 10000001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    {
        int a, b, c;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
        }
    }
    for (int i = 0; i < n; i++)
        graph[i][i] = 0;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF)
                cout << "0 ";
            else
                cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}