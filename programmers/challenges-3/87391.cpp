#include <vector>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = 0;
    int row_begin = x, row_end = x;
    int column_begin = y, column_end = y;
    int size = queries.size();
    int dir, amount;
    for (int i = size - 1; i >= 0; i--) {
        dir = queries[i][0];
        amount = queries[i][1];
        switch(dir) {
            case 0:
                if (column_begin != 0)
                    column_begin += amount;
                column_end = min(m - 1, column_end + amount);
                break;
            case 1:
                column_begin = max(0, column_begin - amount);
                if (column_end != m - 1)
                    column_end -= amount;
                break;
            case 2:
                if (row_begin != 0)
                    row_begin += amount;
                row_end = min(n - 1, row_end + amount);
                break;
            case 3:
                row_begin = max(0, row_begin - amount);
                if (row_end != n - 1)
                    row_end -= amount;
                break;
        }
        if (row_begin > row_end || column_begin > column_end)
            return answer;
    }
    return (long long)(row_end - row_begin + 1) * (long long)(column_end - column_begin + 1);
}