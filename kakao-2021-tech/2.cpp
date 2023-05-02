#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int check_rule(vector<pair<int, int>> &people, vector<string> &room) {
    int count = people.size();
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            int distance = abs(people[i].first - people[j].first) + abs(people[i].second - people[j].second);
            switch(distance) {
                case 1:
                    return 0;
                case 2:
                    if (people[i].first == people[j].first) {
                        if (room[people[i].first][(people[i].second + people[j].second) / 2] != 'X')
                            return 0;
                    } else if (people[i].second == people[j].second) {
                        if (room[(people[i].first + people[j].first) / 2][people[i].second] != 'X')
                            return 0;
                    } else {
                        if (room[people[i].first][people[j].second] != 'X'
                             || room[people[j].first][people[i].second] != 'X')
                            return 0;
                    }
                default:
                    break;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);
    vector<pair<int, int>> people;
    for (int room = 0; room < 5; room++) {
        people.clear();
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (places[room][r][c] == 'P')
                    people.push_back(make_pair(r, c));
            }
        }
        answer[room] = check_rule(people, places[room]);
    }
    
    return answer;
}