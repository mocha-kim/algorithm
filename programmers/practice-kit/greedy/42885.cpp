#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int front_idx = 0;
    int back_idx = people.size() - 1;
    int answer = 0;
    while(front_idx <= back_idx) {
        if (front_idx < back_idx && people[back_idx] + people[front_idx] <= limit) {
            front_idx++;
        }
        back_idx--;
        answer++;
    }
    return answer;
}