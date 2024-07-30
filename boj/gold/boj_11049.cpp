#include <iostream>
#include <vector>
using namespace std;

#define INF 2147483647

struct matrix{
    int r, c;

    matrix() : r(0), c(0) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<matrix> matrices(n);
    for (int i = 0; i < n; i++)
        cin >> matrices[i].r >> matrices[i].c;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int range = 1; range < n; range++) {
        for (int i = 0; i + range < n; i++) {
            int j = i + range;
            dp[i][j] = INF;
            for (int k = i; k < j; k++) {
                int mid_op_count = matrices[i].r * matrices[k].c * matrices[j].c;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mid_op_count);
            }
        }
    }

    cout << dp[0][n - 1];
    return 0;
}