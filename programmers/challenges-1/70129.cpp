#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    map<int, int> count;
    vector<int> answer(2, 0);
    int num = s.length();
    
    if (s == "1")
        return answer;
    {
        int ret = 0, mul = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            answer[s[i] - '0']++;
            ret += (s[i] - '0') * mul;
            mul *= 2;
        }
    }
    answer[1] = answer[0];
    num -= answer[1];
    answer[0] = 1;
    
    while (num != 1) {
        int div, rem;
        while (num != 1) {
            count[num % 2]++;
            num /= 2;
        }
        answer[0]++;
        answer[1] += count[0];
        num = count[1] + 1;
        count.clear();
    }
    return answer;
}