#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> sequence(n);
    cin >> sequence[0];

    vector<int> lis(1);
    lis[0] = sequence[0];
    vector<int> dp(n);
    dp[0] = 1;

    int length = 1;
    for (int i = 1; i < n; i++) {
        cin >> sequence[i];
        if (sequence[i] > lis.back()) {
            lis.push_back(sequence[i]);
            dp[i] = ++length;
        } else {
            vector<int>::iterator begin = lis.begin();
            vector<int>::iterator iter = lower_bound(begin, lis.end(), sequence[i]);
            *iter = sequence[i];
            dp[i] = distance(begin, iter) + 1;
        }
    }

    vector<int> answer(length);
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == length) {
            answer[length - 1] = sequence[i];
            length--;
        }
    }

    length = answer.size();
    cout << length << "\n";
    for (int num : answer)
        cout << num << " ";
    return 0;
}