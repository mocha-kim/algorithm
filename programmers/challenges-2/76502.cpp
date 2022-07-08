#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_valid(string s)
{
    bool has_open_braket = false;
    stack<char> brakets;
    int length = s.size();
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
        {
            brakets.push(s[i]);
            has_open_braket = true;
        }
        else
        {
            if (brakets.empty())
                return false;
            
            if (s[i] == ']' && brakets.top() == '[')
                brakets.pop();
            else if (s[i] == ')' && brakets.top() == '(')
                brakets.pop();
            else if (s[i] == '}' && brakets.top() == '{')
                brakets.pop();
        }
    }
    if (brakets.empty() && has_open_braket)
        return true;
    return false;
}

int solution(string s)
{
    int answer = 0;
    int length = s.size();
    for (int i = 0; i < length; i++)
    {
        if (is_valid(s))
            answer++;
        s = s.substr(1) + s[0];
    }
    return answer;
}