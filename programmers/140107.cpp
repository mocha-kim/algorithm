#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long dd = (long long)d * (long long)d;
    for (int a = 0; a <= d; a += k) {
        int max_b = sqrt(dd - (long long)a * (long long)a);
        answer += floor(max_b / k) + 1;
    }
    return answer;
}