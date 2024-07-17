#include <iostream>
using namespace std;

int g_r, g_c, g_count = 0;

void count_by_split(int x, int y, int n);
	
int main() {
	int n;
	cin >> n >> g_r >> g_c;
	count_by_split(0, 0, n);
	return 0;
}

void count_by_split(int x, int y, int n) {
	if (x == g_r && y == g_c) {
		cout << g_count << "\n";
		return;
	}
	
	int length = 1 << n;
	if (g_r < x || x + length <= g_r || g_c < y || y + length <= g_c) {
		g_count += length * length;
		return;
	}
	
	int half = length / 2;
	count_by_split(x, y, n - 1);
	count_by_split(x, y + half, n - 1);
	count_by_split(x + half, y, n - 1);
	count_by_split(x + half, y + half, n - 1);
}