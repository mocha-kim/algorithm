#include <string>
#include <vector>
#include <set>

using namespace std;

set<set<string>> g_list;

void dfs(int ban_idx, set<string> &list, vector<string> &user_id, vector<string> &banned_id, vector<bool> &is_used) {
    if (ban_idx == banned_id.size()) {
        g_list.insert(list);
        return;
    }
    string ban = banned_id[ban_idx];
    for (int i = 0; i < user_id.size(); i++) {
        if (is_used[i] || user_id[i].length() != ban.length())
            continue;
        bool is_matched = true;
        for (int j = 0; j < user_id[i].length(); j++) {
            if (ban[j] != '*' && ban[j] != user_id[i][j]) {
                is_matched = false;
                break;
            }
        }
        if (is_matched) {
            is_used[i] = true;
            list.insert(user_id[i]);
            dfs(ban_idx + 1, list, user_id, banned_id, is_used);
            list.erase(user_id[i]);
            is_used[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<bool> is_used(user_id.size(), false);
    set<string> list;
    dfs(0, list, user_id, banned_id, is_used);
    return g_list.size();
}