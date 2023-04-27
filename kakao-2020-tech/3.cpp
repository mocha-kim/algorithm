#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    map<string, int> count;
    for (string gem : gems) {
        count[gem] = 0;
    }
    int size = gems.size();
    int type_count = count.size();
    count.clear();
    int left = 0, right = 0;
    vector<int> answer(2);
    answer[0] = 1;
    answer[1] = size;
    while(left < size && right < size) {
        if (count.size() < type_count) {
            count[gems[right]]++;
            right++;
        } else {
            if (right - left - 1 < answer[1] - answer[0]) {
                answer[0] = left + 1;
                answer[1] = right;
            }
            if (count[gems[left]] > 0) {
                count[gems[left]]--;
                if (count[gems[left]] == 0)
                    count.erase(gems[left]);
                left++;
            }
        }
    }
    while(left < size) {
        if (count.size() == type_count && right - left - 1 < answer[1] - answer[0]) {
            answer[0] = left + 1;
            answer[1] = right;
        }
        if (count[gems[left]] > 0) {
            count[gems[left]]--;
            if (count[gems[left]] == 0)
                count.erase(gems[left]);
            left++;
        }
    }
    return answer;
}

/* 남은 left 쪽 처리를 위해 같은 while문을 두 번 도는 게 마음에 안 드는 코드.. */