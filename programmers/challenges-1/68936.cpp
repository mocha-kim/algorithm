#include <string>
#include <vector>

using namespace std;

void solve(int zip, int x, int y, vector<vector<int>> &acc, vector<int> &answer) {
    int sum;
    int end_x = x + zip - 1;
    int end_y = y + zip - 1;
    
    int a = (y == 0) ? 0 : acc[y - 1][end_x];
    int b = (x == 0) ? 0 : acc[end_y][x - 1];
    int c = (x == 0 || y == 0) ? 0 : acc[y - 1][x - 1];
    sum = acc[end_y][end_x] - a - b + c;
    
    if (sum == 0) {
        answer[0]++;
        return;
    } else if (sum == zip * zip) {
        answer[1]++;
        return;
    }
        
    int next = zip / 2;
    solve(next, x, y, acc, answer);
    solve(next, x + next, y, acc, answer);
    solve(next, x, y + next, acc, answer);
    solve(next, x + next, y + next, acc, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    int n = arr.size();
    vector<int> answer(2);
    
    vector<vector<int>> acc(n, vector<int>(n));
    acc[0][0] = arr[0][0];
    for (int i = 1; i < n; i++) {
        acc[i][0] = acc[i - 1][0] + arr[i][0];
        acc[0][i] = acc[0][i - 1] + arr[0][i];
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            acc[j][i] = arr[j][i] + acc[j - 1][i] + acc[j][i - 1] - acc[j - 1][i - 1];
    
    solve(n, 0, 0, acc, answer);
    return answer;
}

/* 괜히 누적합으로 풀었다.. */
/* 그냥 단순히 순회하면서 체크하는게 속도가 더 빠름 */