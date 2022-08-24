#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int calc_fee(int min, const vector<int> fees)
{
	if (min - fees[0] > 0)
	{
		int div = (min - fees[0]) / fees[2];
		int rem = (min - fees[0]) % fees[2];
		return (rem == 0 ? div : div + 1) * fees[3] + fees[1];
	}
	else
		return fees[1];
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
	unordered_map<string, int> checks;
	unordered_map<string, int> logs;
	map<string, int> total_mins;

	for (string record : records)
	{
		size_t first = record.find(' ');
		string time = record.substr(0, first);
		int hour = stoi(time.substr(0, 2));
		int min = stoi(time.substr(3, 2));
		size_t second = record.find(' ', first + 1);
		string car_num = record.substr(first + 1, second - first - 1);
		if (checks[car_num])
		{
			checks[car_num] = 0;
			total_mins[car_num] += hour * 60 + min - logs[car_num];
		}
		else
		{
			checks[car_num] = 1;
			logs[car_num] = hour * 60 + min;
		}
	}

	for (auto check : checks)
	{
		if (check.second)
		{
			checks[check.first]--;
			total_mins[check.first] += 23 * 60 + 59 - logs[check.first];
		}
	}

	for (auto m : total_mins)
		answer.push_back(calc_fee(m.second, fees));

    return answer;
}