#include <string>
#include <vector>

using namespace std;

bool find_jump(vector<int> &stones, int cur, int k) {
    int count = 0;
    for (int stone : stones) {
        if (stone < cur) {
            count++;
        } else {
            count = 0;
        }
        if (count == k) {
            return false;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int min = 1;
    int max = 200000000;
    while (min <= max) {
        int cur = (min + max) / 2;
        if (find_jump(stones, cur, k)) {
            answer = cur;
            min = cur + 1;
        } else {
            max = cur - 1;
        }
    }
    return answer;
}