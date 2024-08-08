#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> array(n, vector<int>(4));
    for (int i = 0; i < n; i++)
        cin >> array[i][0] >> array[i][1] >> array[i][2] >> array[i][3];
    
    vector<int> ab;
    vector<int> cd;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(array[i][0] + array[j][1]);
            cd.push_back(array[i][2] + array[j][3]);
        }
    }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    long long count = 0;
    auto ab_max = ab.end(), ab_iter = ab.begin();
    auto cd_min = cd.rend(), cd_iter = cd.rbegin();
    while (ab_iter != ab_max && cd_iter != cd_min) {
        int sum = *ab_iter + *cd_iter;
        if (sum < 0) {
            ab_iter++;
        } else if (sum > 0) {
            cd_iter++;
        } else {
            long long ab_count = 0, cd_count = 0;
            int ab_num = *ab_iter, cd_num = *cd_iter;
            while(ab_iter != ab_max && *ab_iter == ab_num) {
                ab_iter++;
                ab_count++;
            }
            while(cd_iter != cd_min && *cd_iter == cd_num) {
                cd_iter++;
                cd_count++;
            }
            count += ab_count * cd_count;
        }
    }

    cout << count;
    return 0;
}