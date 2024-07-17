#include <iostream>
#include <queue>
using namespace std;

struct schedule {
    int start;
    int end;

    schedule(int s, int e): start(s), end(e) {}
};

struct compare {
    bool operator()(schedule &s1, schedule &s2) {
        if (s1.end == s2.end)
            return s1.start > s2.start;
        else 
            return s1.end > s2.end;
    }
};

int main() {
    int n;
    cin >> n;
    int start, end;
    priority_queue<schedule, vector<schedule>, compare> pq;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        pq.push(schedule(start, end));
    }

    int count = 1;
    int end_time = pq.top().end;
    pq.pop();
    while (!pq.empty()) {
        if (end_time <= pq.top().start) {
            end_time = pq.top().end;
            count++;
        }
        pq.pop();
    }
    cout << count;
    return 0;
}