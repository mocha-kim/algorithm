#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1);
    int i = left % n;
    int j = left / n;
    for (int k = 0; k < right - left + 1; k++) {
        answer[k] = i > j ? i + 1 : j + 1;
        i++;
        if (i >= n) {
            i = 0;
            j++;
        }
    }
    return answer;
}