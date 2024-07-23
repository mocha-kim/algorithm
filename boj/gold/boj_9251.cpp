#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int s1_size = s1.length();
    int s2_size = s2.length();

    // count of consecutive same character
    vector<vector<int>> dp(s1_size + 1, vector<int>(s2_size + 1));
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[s1_size][s2_size] << "\n";
    return 0;
}