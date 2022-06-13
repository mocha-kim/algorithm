#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string convert(int num, int base)
{
	string result;

	if (base == 10)
		return to_string(num);

	while (num >= base)
	{
        int remain = num % base;
		result.append(to_string(remain));
		num /= base;
	}
	result.append(to_string(num));
	reverse(result.begin(), result.end());
	return result;
}

vector<long> split_by_zero(string str)
{
	vector<long> result;

	size_t start = 0;
	size_t end = 0;

	start = str.find_first_not_of("0");
	while (start != string::npos)
	{
		end = str.find('0', start);
		string num = str.substr(start, end - start);
		if (num != "1")
			result.push_back(stol(num));
		start = str.find_first_not_of("0", end);
	}
	if (result.size() == 0)
		result.push_back(stol(str));
	return result;
}

bool is_prime(long num)
{
	for(long i = 2; i * i <=num; i++)
		if((num % i) == 0)
			return false;
	return true;
}

int count_prime(const vector<long> nums)
{
	int count = 0;
	for (long num : nums)
	{
		if (is_prime(num))
			count++;
	}
	return count;
}

int solution(int n, int k)
{
	string converted = convert(n, k);
	vector<long> splitted = split_by_zero(converted);
    return count_prime(splitted);
}