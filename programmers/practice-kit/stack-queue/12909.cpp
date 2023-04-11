#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> check;
    for (char c : s)
    {
        if (c == '(')
            check.push('(');
        else if (c == ')')
        {
            if (check.empty())
                return false;
            check.pop();
        }
    }
    if (check.empty())
        return true;
    else
        return false;
}