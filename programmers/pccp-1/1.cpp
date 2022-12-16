#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string solution(string input_string) {
    vector<char> save;
    unordered_map<char, int> count;
    char pre = ' ';
    for (char c : input_string) {
        count[c]++;
        if (count[c] > 1 && pre != c) {
            save.push_back(c);
            count[c] = -9999;
        }
        pre = c;
    }
    
    if (save.size() == 0)
        return "N";
    
    sort(save.begin(), save.end());
    string answer = "";
    for (char c : save)
        answer += c;
    return answer;
}