#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int height = triangle.size();
    vector<vector<int> > memo(height, vector<int>(height, -1));
    memo[0][0] = triangle[0][0];
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            memo[i + 1][j] = max(memo[i + 1][j], memo[i][j] + triangle[i + 1][j]);
            memo[i + 1][j + 1] = max(memo[i + 1][j + 1], memo[i][j] + triangle[i + 1][j + 1]);
        }
    }
    int answer = -1;
    for (int i : memo[height - 1])
        answer = max(answer, i);
    return answer;
}