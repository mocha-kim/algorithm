#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int length = number.length() - k;
    answer.reserve(length);
    int start_idx = 0;
    for (int i = 0; i < length; i++)
    {
        int max_idx = start_idx;
        char max = number[max_idx];
        for(int j = start_idx; j <= i + k; j++)
        {
            if (max < number[j])
            {
                max_idx = j;
                max = number[max_idx];
                if (max == '9')
                    break;
            }
        }
        answer += max;
        start_idx = max_idx + 1;
    }
	return answer;
}