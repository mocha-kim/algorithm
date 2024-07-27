#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> sequence(n);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    
    int max_length = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        max_length = max(max_length, dp[i]);
    }
    cout << max_length;
    return 0;
}