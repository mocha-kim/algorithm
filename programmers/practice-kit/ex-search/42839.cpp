#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int num)
{
    if (num == 0 || num == 1)
        return false;

    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    
    return true;
}

int solution(string numbers)
{
    int length = numbers.length();
    vector<char> nums(length);
    for (int i = 0; i < length; i++)
        nums[i] = numbers[i];
    sort(nums.begin(), nums.end());
    
    vector<int> joins;
    do
    {
        string tmp = "";
        for (int i = 0; i < length; i++)
        {
            tmp += nums[i];
            joins.push_back(stoi(tmp));
        }
    } while (next_permutation(nums.begin(), nums.end()));
    sort(joins.begin(), joins.end());
    joins.erase(unique(joins.begin(), joins.end()), joins.end());
    int answer = 0;
    for (int i : joins)
        if (is_prime(i))
            answer++;
    return answer;
}