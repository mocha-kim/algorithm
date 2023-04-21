#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int size = a.size();
    if (size < 3)
        return size;
    
    int min_idx = 0;
    for (int i = 0; i < size; i++)
        min_idx = a[min_idx] < a[i] ? min_idx : i;
    
    int answer = size;
    {
        vector<int> pre_min(size, 1000000001);
        for (int i = 1; i < min_idx; i++) {
            pre_min[i] = min(pre_min[i - 1], a[i - 1]);
            if (pre_min[i] < a[i])
                answer--;
        }
    }
    {
        vector<int> next_min(size, 1000000001);
        for (int i = size - 2; i > min_idx; i--) {
            next_min[i] = min(next_min[i + 1], a[i + 1]);
            if (next_min[i] < a[i])
                answer--;
        }
    }
    return answer;
}