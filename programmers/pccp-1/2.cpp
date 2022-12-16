#include <string>
#include <vector>

using namespace std;

int g_answer = -1;
int g_students, g_sports;

void dfs(int sum, int idx, vector<vector<int>> &ability, vector<bool> &is_chosen) {
    if (idx == g_sports) {
        if (sum > g_answer)
            g_answer = sum;
        return;
    }
    
    for (int i = 0; i < g_students; i++) {
        if (is_chosen[i])
            continue;
        is_chosen[i] = true;
        dfs(sum + ability[i][idx], idx + 1, ability, is_chosen);
        is_chosen[i] = false;
    }
}

int solution(vector<vector<int>> ability) {
    g_students = ability.size();
    g_sports = ability[0].size();
    vector<bool> is_chosen(10, false);
    dfs(0, 0, ability, is_chosen);
    return g_answer;
}