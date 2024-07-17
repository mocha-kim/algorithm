#include <iostream>
#include <vector>
using namespace std;

int g_white = 0;
int g_blue = 0;

void check_color(int r, int c, int size, vector<vector<int> > &paper);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int> > paper(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }


    check_color(0, 0, n, paper);
    cout << g_white << "\n" << g_blue;
    return 0;
}

void check_color(int r, int c, int size, vector<vector<int> > &paper) {
    int color = paper[c][r];
    for (int i = c; i < size + c; i++) {
        for (int j = r; j < size + r; j++) {
            if (paper[i][j] == color)
                continue;
            int half = size / 2;
            check_color(r, c, half, paper);
            check_color(r + half, c, half, paper);
            check_color(r, c + half, half, paper);
            check_color(r + half, c + half, half, paper);
            return;
        }
    }

    if (color == 0)
        g_white++;
    else
        g_blue++;
    return;
}