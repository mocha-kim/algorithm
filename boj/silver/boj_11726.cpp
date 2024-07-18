#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[10001] = { 1, 1, 0, };
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout << dp[n];
    return 0;
}