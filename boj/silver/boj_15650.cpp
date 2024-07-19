#include <iostream>
#include <vector>
using namespace std;

int g_n, g_m;

void dfs(int cur, int size, vector<int> &selected, vector<bool> &is_visited);

int main() {
    cin >> g_n >> g_m;
    vector<int> selected(g_m);
    vector<bool> is_visited(g_m, false);
    dfs(0, 0, selected, is_visited);
    return 0;
}

void dfs(int cur, int size, vector<int> &selected, vector<bool> &is_visited) {
    if (size == g_m) {
        for (int i = 0; i < g_m; i++)
            cout << selected[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = cur; i < g_n; i++) {
        if (is_visited[i])
            continue;
        is_visited[i] = true;
        selected[size] = i + 1;
        dfs(i + 1, size + 1, selected, is_visited);
        is_visited[i] = false;
    }
}