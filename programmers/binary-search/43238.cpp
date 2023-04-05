#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long min = 1;
    long long max = (long long)times.back() * (long long)n;
    long long answer, cur, capacity;
    while (min <= max) {
        cur = (min + max) / 2;
        capacity = 0;
        for (int time : times) {
            capacity += cur / (long long)time;
        }
        
        if (n <= capacity) {
            max = cur - 1;
            answer = cur;
        } else {
            min = cur + 1;
        }
    }
    return answer;
}