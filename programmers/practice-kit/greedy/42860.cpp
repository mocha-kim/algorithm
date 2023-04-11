#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int length = name.length();
    int hori_move = length - 1;
    for (int i = 0; i < length; i++)
    {
        if (name[i] - 'A' < 14)
            answer += name[i] - 'A';
        else
            answer += 'Z' - name[i] + 1;
        int next = i + 1;
        while (next < length && name[next] == 'A')
            next++;
		// hori_move : previous max value
		// i + length - next : move left direction
		// min(i, length - next) : check front values(i) first or last values(lengt - next) first
        hori_move = min(hori_move, i + length - next + min(i, length - next));
    }
    answer += hori_move;
    return answer;
}