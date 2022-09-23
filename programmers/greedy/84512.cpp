#include <string>
#include <vector>

using namespace std;

#define COUNT 5

string g_end, g_alpha = "AEIOU";
int g_answer = 0;
bool g_is_found = false;

void dfs(string cur)
{
	if (cur.length() > COUNT || g_is_found)
		return;
	if (cur == g_end)
	{
        g_is_found = true;
		return;
	}
    
	g_answer++;
	for (int i = 0; i < COUNT; i++)
		dfs(cur + g_alpha[i]);
}

int solution(string word)
{
	g_end = word;
	
	dfs("");
    return g_answer;
}