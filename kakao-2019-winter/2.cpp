#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    int tuple_count = -1;
    int start = 0, end;
    unordered_map<int, int> num;
    while(start < s.length() - 1) {
        end = s.find("}", start);
        string tuple = s.substr(start + 2, end - start - 2);
        int num_start = 0, num_end;
        while((num_end = tuple.find(",", num_start)) != string::npos) {
            num[stoi(tuple.substr(num_start, num_end - num_start))]++;
            num_start = num_end + 1;
        }
        num[stoi(tuple.substr(num_start))]++;
        start = end + 1;
    }
    vector<pair<int, int>> sorted_num(num.begin(), num.end());
    sort(sorted_num.begin(), sorted_num.end(), compare);
    vector<int> answer;
    answer.reserve(500);
    for (pair<int, int> p : sorted_num) {
        answer.push_back(p.first);
    }
    return answer;
}