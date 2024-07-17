#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> trees(n);
    for (int i = 0; i < n; i++)
        cin >> trees[i];
        
    int min = 1;
    int max = 2000000000;
    while(min <= max) {
        long long sum = 0;
        int cur = ((long long)min + max) / 2;
        
        for (int i = 0; i < n; i++)
            if (trees[i] > cur)
                sum += trees[i] - cur;
        
        if (sum < m)
            max = cur - 1;
        else
            min = cur + 1;
    }
    cout << min - 1;
    return 0;
}