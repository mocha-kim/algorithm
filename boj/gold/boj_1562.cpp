#include <iostream>
#include <vector>
using namespace std;

#define MAX 1 << 10
#define MOD 1000000000

int main() {
    int n;
    cin >> n;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(10, vector<int>(MAX, 0)));
    for (int i = 1; i < 10; i++)
        dp[1][i][1 << i] = 1;
    
    for (int length = 2; length <= n; length++) {
        for (int digit = 0; digit < 10; digit++) {
            for (int cur = 0; cur < MAX; cur++) {
                int mask = cur | 1 << digit;
                if (digit > 0)
                    dp[length][digit][mask] = (dp[length][digit][mask] + dp[length - 1][digit - 1][cur]) % MOD;
                if (digit < 9)
                    dp[length][digit][mask] = (dp[length][digit][mask] + dp[length - 1][digit + 1][cur]) % MOD;
            }
        }
    }

    int all_mask = (MAX) - 1;
    int answer = 0;
    for (int i = 0; i < 10; i++)
        answer = (answer + dp[n][i][all_mask]) % MOD;
    cout << answer;
    return 0;
}