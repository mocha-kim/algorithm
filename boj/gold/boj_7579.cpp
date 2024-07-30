#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> memory(n);
    for (int i = 0; i < n; i++)
        cin >> memory[i];
    
    int max_cost = 0;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        max_cost += cost[i];
    }

    vector<int> dp(max_cost + 1, 0);
    for (int i = 0; i < n; i++)
        for (int c = max_cost; c >= cost[i]; c--)
            dp[c] = max(dp[c], dp[c - cost[i]] + memory[i]);

    for (int c = 0; c <= max_cost; c++) {
        if (dp[c] >= m) {
            cout << c << "\n";
            break;
        }
    }
    return 0;
}