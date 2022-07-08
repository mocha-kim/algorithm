#include <string>
#include <vector>

using namespace std;

long long solve(long long x)
{
    if (x % 2 == 0)
        return x + 1;
    long long tmp = x;
    long long binary_n = 2;
    while (true)
    {
        if (x < binary_n)
            return x + binary_n - binary_n / 2;
        if (tmp % 2 == 0)
            return x + binary_n / 2 -  binary_n / 4;
        else
            tmp = tmp / 2;
        binary_n *= 2;
    }
    return x;
}

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    answer.reserve(numbers.size());
    for (auto i : numbers)
        answer.push_back(solve(i));
    return answer;
}