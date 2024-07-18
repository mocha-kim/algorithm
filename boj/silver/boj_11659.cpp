#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int x;
    vector<long long> sum(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        cin >> x;
        sum[i] = x + sum[i - 1];
    }

    int y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << sum[y] - sum[x - 1] << "\n";
    }
    return 0;
}