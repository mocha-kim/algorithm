#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int> > graph(n + 1);
    for (vector<int> e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    queue<pair<int, int> > q;
    vector<bool> is_visited(n + 1, false);
    vector<int> distance(n + 1);
    
    q.push(make_pair(1, 0));
    is_visited[1] = true;
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int next : graph[cur.first]) {
            if (!is_visited[next]) {
                q.push(make_pair(next, cur.second + 1));
                distance[next] = cur.second + 1;
                is_visited[next] = true;
            }
        }
    }
    
    int answer = 0;
    int max = distance[0];
    for (int val : distance) {
        if (val == max) {
            answer++;
        } else if (val > max) {
            max = val;
            answer = 1;
        }
    }
    return answer;
}