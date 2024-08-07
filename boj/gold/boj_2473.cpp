#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 3000000001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> solutions(n);
    for (int i = 0; i < n; i++)
        cin >> solutions[i];
    sort(solutions.begin(), solutions.end());
    
    long long min_gap = INF;
    int min, mid, max;
    for (int min_idx = 0; min_idx < n - 2; min_idx++) {
        int mid_idx = min_idx + 1, max_idx = n - 1;
        while (mid_idx < max_idx) {
            long long value = (long long)solutions[min_idx] + solutions[mid_idx] + solutions[max_idx];
            if (abs(value) < min_gap) {
                min_gap = abs(value);
                min = solutions[min_idx];
                mid = solutions[mid_idx];
                max = solutions[max_idx];
            }
            if (value > 0)
                max_idx--;
            else
                mid_idx++;
        }
    }
    cout << min << " " << mid << " " << max << "\n";
    return 0;
}