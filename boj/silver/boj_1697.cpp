#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	const int max = 100000 * 2;
	int time[max] = { 0 };
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if (cur == k) {
			cout << time[cur];
			break;
		}
		
		int next = cur + 1;
		if (next >= 0 && next <= max && time[next] == 0) {
			q.push(next);
			time[next] = time[cur] + 1;
		}
		next = cur - 1;
		if (next >= 0 && next <= max && time[next] == 0) {
			q.push(next);
			time[next] = time[cur] + 1;
		}
		next = cur * 2;
		if (next >= 0 && next <= max && time[next] == 0) {
			q.push(next);
			time[next] = time[cur] + 1;
		}
	}
	return 0;
}