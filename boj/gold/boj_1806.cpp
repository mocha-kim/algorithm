#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++)
        cin >> sequence[i];

    int sum = 0, length = MAX;
    int begin = 0, end = 0;
    while (begin <= end) {
        if (sum >= s) {
            length = min(length, end - begin);
            sum -= sequence[begin++];
        } else {
            if (end == n)
                break;
            sum += sequence[end++];
        }
    }

    if (length == MAX)
        cout << "0\n";
    else
        cout << length << "\n";
    return 0;
}