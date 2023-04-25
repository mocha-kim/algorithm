#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool is_right = (hand == "right") ? true : false;
    int cur_r = 10, cur_l = 12;
    for (int i : numbers) {
        switch(i) {
            case 1:
            case 4:
            case 7:
                cur_l = i;
                answer += "L";
                break;
            case 3:
            case 6:
            case 9:
                cur_r = i;
                answer += "R";
                break;
            default:
                int tmp = (i == 0) ? 11 : i;
                int dist_r = abs(tmp - cur_r) / 3 + abs(tmp - cur_r) % 3;
                int dist_l = abs(tmp - cur_l) / 3 + abs(tmp - cur_l) % 3;
                if (dist_r < dist_l) {
                    cur_r = tmp;
                    answer += "R";
                } else if (dist_r > dist_l) {
                    cur_l = tmp;
                    answer += "L";
                } else {
                    if (is_right) {
                        cur_r = tmp;
                        answer += "R";
                    } else {
                        cur_l = tmp;
                        answer += "L";
                    }
                }
                break;
        }
    }
    return answer;
}