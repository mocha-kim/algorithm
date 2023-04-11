#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    vector<string> str_nums(numbers.size());
    for (int i = 0; i < numbers.size(); i++)
        str_nums[i] = to_string(numbers[i]);
    sort(str_nums.begin(), str_nums.end(), compare);
    if (str_nums[0].compare("0") == 0)
        return "0";
    string answer = "";
    for (string str : str_nums)
        answer.append(str);
    return answer;
}