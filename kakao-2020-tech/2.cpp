#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

char g_priority[6][3] = {{'+', '-', '*'}, {'+', '*', '-'},
                        {'-', '+', '*'}, {'-', '*', '+'},
                        {'*', '+', '-'}, {'*', '-', '+'}};

struct Term {
    bool is_num;
    long long num;
    char oper;

    Term(long long ll) {
        is_num = true;
        num = ll;
    }

    Term(char c) {
        is_num = false;
        oper = c;
    }
};

long long calc(char oper, long long a, long long b) {
    switch(oper) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
    return 0;
}

long long solution(string expression) {
    vector<Term> parsed;
    {
        string num = "";
        for (char c : expression) {
            if (c == '+' || c == '-' || c == '*') {
                parsed.push_back(Term(stoll(num)));
                num = "";
                string tmp(1, c);
                parsed.push_back(Term(c));
            } else {
                num += c;
            }
        }
        parsed.push_back(Term(stoll(num)));
    }
    
    long long answer = 0;
    priority_queue<long long, vector<long long>, less<long long> > ret;
    for (int i = 0; i < 6; i++) {
        vector<Term> tmp = parsed;
        for (int j = 0; j < 3; j++) {
            for (int k = 1; k < tmp.size(); k += 2) {
                if (tmp[k].oper == g_priority[i][j]) {
                    tmp[k - 1].num = calc(tmp[k].oper, tmp[k - 1].num, tmp[k + 1].num);
                    tmp.erase(tmp.begin() + k, tmp.begin() + k + 2);
                    k -= 2;
                }
            }
        }
        ret.push(abs(tmp[0].num));
    }
    return ret.top();
}