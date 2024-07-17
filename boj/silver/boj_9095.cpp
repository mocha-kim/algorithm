#include <iostream>
using namespace std;

int g_count;

void dfs(int sum, int n);

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        g_count = 0;
        dfs(0, n);
        cout << g_count << "\n";
    }
    return 0;
}

void dfs(int sum, int n) {
    if (sum == n) {
        g_count++;
        return;
    } else if (sum > n) {
        return;
    }

    dfs(sum + 1, n);
    dfs(sum + 2, n);
    dfs(sum + 3, n);
}