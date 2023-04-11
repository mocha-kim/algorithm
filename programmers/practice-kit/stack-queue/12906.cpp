#include <vector>
#include <algorithm>
// #include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
	// stack<int> unique;
	// unique.push(arr[0]);
	// for (int i : arr)
	// 	if (unique.top() != i)
	// 		unique.push(i);

	// int size = unique.size();
	// vector<int> answer(size);
	// for (int i = size - 1; i >= 0; i--)
	// {
	// 	answer[i] = unique.top();
	// 	unique.pop();
	// }
    // return answer;
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<int> answer = arr;
    return answer;
}