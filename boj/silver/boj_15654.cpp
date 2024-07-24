#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int g_n, g_m;
int seq[8];

void dfs(int count, vector<int>& numbers, vector<bool>& is_visited);

int main() {
    cin >> g_n >> g_m;
    vector<int> numbers(g_n);
    for (int i = 0; i < g_n; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    vector<bool> is_visited(g_n, false);
    dfs(0, numbers, is_visited);
    return 0;
}

void dfs(int count, vector<int>& numbers, vector<bool>& is_visited) {
    if (count == g_m) {
        for (int i = 0; i < g_m; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < g_n; i++) {
        if (is_visited[i])
            continue;
        seq[count] = numbers[i];
        is_visited[i] = true;
        dfs(count + 1, numbers, is_visited);
        is_visited[i] = false;
    }
}