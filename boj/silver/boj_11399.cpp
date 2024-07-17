#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, t;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> t;
        pq.push(t);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        t = pq.top();
        pq.pop();
        sum += t * (n - i);
    }
    cout << sum;
    return 0;
}