#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    unordered_map<char, int> types;
	int size = survey.size();
	for (int i = 0; i < size; i++)
	{
		int div = choices[i] / 4;
		int rem = choices[i] % 4;
		if (div < 1)	// negative
			types[survey[i][0]] += 4 - rem;
		else			// positive
			types[survey[i][1]] += rem;
	}
    string answer = "";
	answer.push_back(types['R'] < types['T'] ? 'T' : 'R');
	answer.push_back(types['C'] < types['F'] ? 'F' : 'C');
	answer.push_back(types['J'] < types['M'] ? 'M' : 'J');
	answer.push_back(types['A'] < types['N'] ? 'N' : 'A');
    return answer;
}