#include <string>
#include <vector>

using namespace std;

int g_answer;
int g_size;
string g_target;

bool is_one_diff(string s1, string s2)
{
    int count = 0;
    size_t length = s1.length();
    for (int i = 0; i < length; i++)
        if (s1[i] != s2[i])
            count++;
    return count == 1;
}

void dfs(string cur, int count, vector<string> &words,  vector<bool> &used)
{
    if (count > g_answer)
        return;
    
    if (cur == g_target)
    {
        if (g_answer > count)
        {
            g_answer = count;
            return;
        }
    }
    
    for (int i = 0; i < g_size; i++)
    {
        if (!used[i] && is_one_diff(cur, words[i]))
        {
            used[i] = true;
            dfs(words[i], count + 1, words, used);
            used[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    g_size = words.size();
    g_answer = g_size + 1;
    g_target = target;
    vector<bool> used(g_size, false);
    dfs(begin, 0, words, used);
    if (g_answer == g_size + 1)
        return 0;
    return g_answer;
}