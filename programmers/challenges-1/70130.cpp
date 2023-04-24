#include <string>
#include <vector>
#include <map>

int solution(std::vector<int> a) {
    for (int i = 0; i < a.size() - 2; i++) {
        if (a[i] == a[i + 1]) {
            a[i] = -1;
        } else {
            break;
        }
    }
    int size = a.size();
    if (size < 2)
        return 0;
    
    std::map<int, int> count;
    for (int i : a) {
        count[i]++;
    }
    count[-1] = -1;
    std::pair<int, int> max(-1, -1);
    for (std::pair<int, int> p : count) {
        if (max.second < p.second) {
            max.first = p.first;
            max.second = p.second;
        }
    }
    int answer = 0;
    if (a[0] == max.first && a[1] != max.first) {
        a[0] = -1;
        a[1] = -1;
        answer += 2;
    }
    for (int i = 1; i < size - 1; i++) {
        if (a[i] == max.first) {
            if (a[i - 1] != -1 && a[i - 1] != max.first) {
                a[i - 1] = -1;
                a[i] = -1;
                answer += 2;
            } else if (a[i + 1] != -1 && a[i + 1] != max.first) {
                a[i + 1] = -1;
                a[i] = -1;
                answer += 2;
            }
        }
    }
    if (a[size - 1] == max.first && a[size - 2] != -1 && a[size - 2] != max.first) {
        answer += 2;
    }
    return answer;
}