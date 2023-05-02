#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, int> words;
    words["zero"] = 1;
    words["one"] = 2;
    words["two"] = 3;
    words["three"] = 4;
    words["four"] = 5;
    words["five"] = 6;
    words["six"] = 7;
    words["seven"] = 8;
    words["eight"] = 9;
    words["nine"] = 10;
    
    int answer = 0;
    string tmp = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            answer = answer * 10 + c - '0';
        } else {
            tmp += c;
            if (words[tmp] > 0) {
                answer = answer * 10 + words[tmp] - 1;
                tmp = "";
            }
        }
    }
    return answer;
}