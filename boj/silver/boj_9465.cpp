#include <iostream>
#include <vector>
using namespace std;

#define ROW 2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    int n;
    vector<vector<int>> stickers(ROW);
    for (int test = 0; test < t; test++) {
        cin >> n;
        for (int i = 0; i < ROW; i++) {
            stickers[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> stickers[i][j];
        }
        vector<vector<int>> dp(ROW, vector<int>(n, 0));
        dp[0][0] = stickers[0][0];
        dp[1][0] = stickers[1][0];
        dp[0][1] = stickers[0][1] + dp[1][0];
        dp[1][1] = stickers[1][1] + dp[0][0];
        for(int i = 2; i < n; i++) {
            dp[0][i] = stickers[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = stickers[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
    return 0;
}