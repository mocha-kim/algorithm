#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare_score {
    bool operator()(vector<int> &p1, vector<int> &p2)
    {
        if (p1[0] == p2[0])
            return p1[1] > p2[1];
        return p1[0] > p2[0];
    }
};

bool compare_called(vector<int> &p1, vector<int> &p2) {
    if (p1[1] == p2[1])
        return p1[0] < p2[0];
    return p1[1] < p2[1];
};

vector<long long> solution(vector<vector<int>> program) {
    int size = program.size();
    vector<long long> answer(11);
    priority_queue<vector<int>, vector<vector<int>>, compare_score> pq;
    sort(program.begin(), program.end(), compare_called);
    long long time = 0;
    int excuted_count = 0;
    int idx = 0;
    while (excuted_count < size) {
        // 실행 가능한 프로그램은 큐에 넣기
        while (idx < size && program[idx][1] <= time) {
            pq.push(program[idx]);
            idx++;
        }
        
        if (pq.empty()) {
            // 실행 가능한 프로그램이 없으면 시간 업데이트
            time = program[idx][1];
        } else {
            // 실행 가능한 프로그램이 있으면 꺼내서 실행
            auto cur = pq.top();
            pq.pop();
            answer[cur[0]] += (long long)(time - cur[1]);
            time += (long long)cur[2];
            excuted_count++;
        }
    }
    answer[0] = time;
    return answer;
}