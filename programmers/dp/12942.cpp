#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int size = matrix_sizes.size();
    vector<vector<int> > dp(size, vector<int>(size, 999999999));
    for (int i = 0; i < size; i++)
        dp[i][i] = 0;
    
    // dp[a][b] : a번째 ~ b번째 행렬들을 다 곱했을 때 최소 연산 수
    // dp[a][b] = [(a) ~ (k) 연산 수] + [(k + 1) ~ (b) 연산 수] + [그 두 연산의 결과로 나온 행렬의 연산 수]
    // a * k * b => (tmp[a[0]][k[1]]의 행렬) * b => (res[a[0]][b[1]]의 행렬)이 됨
    int a, b;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (j == j + i)
                continue;
            a = j;
            b = j + i;
            for (int k = a; k < b; k++)
                dp[a][b] = min(dp[a][b],
                            dp[a][k] + dp[k + 1][b] + matrix_sizes[a][0] * matrix_sizes[k][1] * matrix_sizes[b][1]);
        }
    }
    
    return dp[0][size - 1];
}