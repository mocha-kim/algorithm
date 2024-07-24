#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a;
    cin >> n >> m;

    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a - sum[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
} 