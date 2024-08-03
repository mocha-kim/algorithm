#include <iostream>
#include <vector>
using namespace std;

#define INF 2000000001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> solutions(n);
    for (int i = 0; i < n; i++)
        cin >> solutions[i];

    int min_idx = 0, max_idx = n - 1;
    int min = solutions[min_idx], max = solutions[max_idx];
    int min_gap = INF;
    while (min_idx < max_idx) {
        int value = solutions[min_idx] + solutions[max_idx];
        if (abs(value) < min_gap) {
            min_gap = abs(value);
            min = solutions[min_idx];
            max = solutions[max_idx];
        }
        if (value > 0)
            max_idx--;
        else
            min_idx++;
    }
    cout << min << " " << max << "\n";
    return 0;
}