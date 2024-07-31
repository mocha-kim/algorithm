#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> lis(1);
    cin >> lis[0];

    int num;
    for (int i = 1; i < n; i++) {
        cin >> num;
        if (num <= lis.back()) {
            *lower_bound(lis.begin(), lis.end(), num) = num;
            continue;
        }
        lis.push_back(num);
    }
    cout << lis.size();
    return 0;
}