#include <string>
#include <vector>
#include <map>

using namespace std;

void find_comb(int i, vector<map<int, int> > &memo) {
    for (int j = 0; j < i; j++) {
        for (auto a : memo[j]) {
            for (auto b : memo[i - j - 1]) {
                memo[i][a.first + b.first]++;
                memo[i][a.first - b.first]++;
                memo[i][a.first * b.first]++;
                if (b.first > 0)
                    memo[i][a.first / b.first]++;
            }
        }
    }
    
}

int solution(int N, int number) {
    int num = 0;
    vector<map<int, int> > memo(8);
    for (int i = 0; i < 8; i++) {
        num += N;
        memo[i][num]++;
        num *= 10;
        find_comb(i, memo);
        auto it = memo[i].find(number);
        if (it != memo[i].end())
            return i + 1;
    }
    return -1;
}