#include <string>
#include <vector>

using namespace std;

bool end_with_oneonezero(string str)
{
    size_t length = str.length();
    return str[length - 3] == '1'
        && str[length - 2] == '1'
        && str[length - 1] == '0';
}

vector<string> solution(vector<string> s)
{
    size_t begin;
    vector<string> answer;
    answer.reserve(s.size());
    for (int i = 0 ; i < s.size(); i++)
    {
        string oneonezeros, tmp;
        for (auto c : s[i])
        {
            tmp += c;
            size_t length = tmp.length();
            if (tmp.size() >= 3 && end_with_oneonezero(tmp))
            {
                oneonezeros += "110";
                tmp.erase(length - 3);
            }
        }
        begin = tmp.rfind('0');
        if (begin == string::npos)
            answer.push_back(oneonezeros + tmp);
        else
            answer.push_back(tmp.insert(begin + 1, oneonezeros));
    }
    return answer;
}