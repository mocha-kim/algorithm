#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int n = board.size();
    vector<queue<int>> cols(n + 1);
    for (vector<int> row : board) {
        for (int i = 0; i < n; i++) {
            if (row[i] != 0) {
                cols[i + 1].push(row[i]);
            }
        }
    }
    
    int answer = 0;
    stack<int> basket;
    basket.push(-1);
    for (int move : moves) {
        if (cols[move].empty())
            continue;
        int cur = cols[move].front();
        cols[move].pop();
        if (basket.top() == cur) {
            basket.pop();
            answer += 2;
        } else {
            basket.push(cur);
        }
    }
    return answer;
}