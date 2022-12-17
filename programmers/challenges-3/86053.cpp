#include <iostream>
#include <vector>

using namespace std;

bool check(long long cur, int a, int b, vector<int> &g, vector<int> &s, vector<int> &w, vector<int> &t) {
    int city_count = g.size();
    long long gold = 0, silver = 0, total = 0;
    long long round_time, max_moves, max_weight;
    
    for (int i = 0; i < city_count; i++) {
        round_time = t[i] * 2;
        max_moves = cur / round_time;
        if (cur % round_time >= t[i])
            max_moves++;
        max_weight = w[i] * max_moves;
        
        gold += min((long long)g[i], max_weight);
        silver += min((long long)s[i], max_weight);
        total += min((long long)g[i] + (long long)s[i], max_weight);
    }
    
    if (gold < a || silver < b || total < a + b)
        return false;
    else
        return true;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long begin = 0, end = 10e9 * 2 * 10e5 * 2 + 10e5, mid;
    long long answer = end;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (check(mid, a, b, g, s, w, t)) {
            answer = min(answer, mid);
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return answer;
}