#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int w, v;
    vector<pair<int, int>> objects(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w >> v;
        objects[i] = { w, v };
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (objects[i].first < j) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - objects[i].first] + objects[i].second);
        }
    }
    cout << dp[n][k];
    return 0;
}