#include <iostream>
#include <vector>
using namespace std;

#define START 0
#define INF 16000001

int g_n;
int g_max_mask;

int dfs(int cur, int visited_mask, vector<vector<int>>& w, vector<vector<int>>& dp);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> g_n;
    g_max_mask = (1 << g_n) - 1;

    vector<vector<int>> w(g_n, vector<int>(g_n));
    for (int i = 0; i < g_n; i++)
        for (int j = 0; j < g_n; j++)
            cin >> w[i][j];

    vector<vector<int>> dp(g_n, vector<int>(1 << g_n, -1));
    cout << dfs(START, 1 << START, w, dp);
    return 0;
}

int dfs(int cur, int visited_mask, vector<vector<int>>& w, vector<vector<int>>& dp) {
    if (visited_mask == g_max_mask) {
        if (w[cur][START] == 0)
            return INF;
        return w[cur][START];
    }

    if (dp[cur][visited_mask] != -1)
        return dp[cur][visited_mask];
    
    dp[cur][visited_mask] = INF;
    for (int i = 0; i < g_n; i++) {
        int i_bit = 1 << i;
        if (w[cur][i] == 0 || (visited_mask & i_bit))
            continue;
        dp[cur][visited_mask] = min(dp[cur][visited_mask], w[cur][i] + dfs(i, visited_mask | i_bit, w, dp));
    }
    return dp[cur][visited_mask];
}