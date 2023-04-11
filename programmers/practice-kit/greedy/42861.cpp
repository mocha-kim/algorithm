#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int g_parents[101];
 
bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int find(int a) {
    if(g_parents[a] == a) {
		return a;
	}
    return g_parents[a] = find(g_parents[a]);
}
 
int solution(int n, vector<vector<int>> costs) {
    for(int i = 0; i < n; i++) {
        g_parents[i] = i;
	}
    
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);
    for(vector<int> cost : costs) {
        int start = find(cost[0]);
        int end = find(cost[1]);
 
        if(start != end) {
            answer += cost[2];
            g_parents[end] = start;
        }
    }
    return answer;
}