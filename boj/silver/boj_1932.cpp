#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<vector<int>> dp(n, vector<int>(n));
    int num;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> dp[i][j];
    
    int max_sum = dp[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0)
                dp[i][j] += dp[i - 1][0]; 
            else if (j == i)
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            max_sum = max(max_sum, dp[i][j]);
        }
    }
    cout << max_sum;
    return 0;
}