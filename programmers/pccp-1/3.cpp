#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solve(int n, int p) {
    if (n == 1)
        return "Rr";
    
    int base = pow(4, n - 2);
    if (p <= base) {            // RR Part
        return "RR";
    } else if (p > 3 * base) {  // rr Part
        return "rr";
    } else {                    // Rr Part
        p = (p - base) % base;
        p = p == 0 ? 4 : p;
        return solve(n - 1, p);
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    for (auto query : queries)
        answer.push_back(solve(query[0], query[1]));
    return answer;
}