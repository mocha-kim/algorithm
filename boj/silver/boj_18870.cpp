#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    vector<int> sorted_unique(numbers);

    sort(sorted_unique.begin(), sorted_unique.end());
    sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());

    auto iter = numbers.begin();
    auto min = sorted_unique.begin();
    for (; iter != numbers.end(); iter++)
        cout << lower_bound(sorted_unique.begin(), sorted_unique.end(), *iter) - min << " ";
    return 0;
}