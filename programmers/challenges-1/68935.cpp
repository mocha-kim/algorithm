#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string num;
    while(n) {
        num += (n % 3) + '0';
        n /= 3;
    }
    int answer = 0;
    int helper = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        answer += (num[i] - '0') * helper;
        helper *= 3;
    }
    return answer;
}