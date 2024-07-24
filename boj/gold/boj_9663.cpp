#include <iostream>
#include <vector>
using namespace std;

int g_n;
int g_answer = 0;

void dfs(int cur, vector<int>& col);

int main() {
    cin >> g_n;

    vector<int> col(g_n);
    dfs(0, col);
    cout << g_answer;
    return 0;
}

void dfs(int cur, vector<int>& col) {
    if (cur == g_n) {
        g_answer++;
        return;
    }

    bool is_valid;
    for (int i = 0; i < g_n; i++) {
        col[cur] = i;
        is_valid = true;
        for (int next = 0; next < cur; next++) {
            if (col[cur] == col[next] || abs(col[cur] - col[next]) == cur - next) {
                is_valid = false;
                break;
            }
        }
        if (is_valid)
            dfs(cur + 1, col);
    }
}