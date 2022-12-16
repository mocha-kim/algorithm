#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> checked(10, false);
    for (int i : numbers)
        checked[i] = true;
    for (int i = 0; i < 10; i++)
        if (!checked[i])
            answer += i;
    return answer;
}