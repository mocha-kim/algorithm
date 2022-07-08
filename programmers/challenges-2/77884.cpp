#include <string>
#include <vector>

using namespace std;

int count_divisor(int n)
{
    if (n == 1)
        return 1;
    int count = 2;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if (i * i != n)
                count++;
        }
    }
    return count;
}

int solution(int left, int right)
{
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        if (count_divisor(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}