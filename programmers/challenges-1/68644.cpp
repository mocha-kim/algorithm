#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    map<int, int> ordered;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            ordered[numbers[i] + numbers[j]]++;
        }
    }
    vector<int> answer;
    answer.reserve(ordered.size());
    for (pair<int, int> p : ordered) {
        answer.push_back(p.first);
    }
    return answer;
}