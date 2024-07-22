#include <iostream>
#include <vector>
using namespace std;

struct road_info {
    int s;
    int e;
    int t;
};

bool bellmanFord(int n, vector<road_info>& graph);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for (int test = 0; test < tc; test++) {
        int n, m, w;
        cin >> n >> m >> w;

        int s, e, t;
        vector<road_info> graph(n + 1);
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            graph.push_back({ s, e, t });
            graph.push_back({ e, s, t });
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            graph.push_back({ s, e, -t });
        }

        cout << (bellmanFord(n, graph) ? "YES\n" : "NO\n");
    }
    return 0;
}

bool bellmanFord(int n, vector<road_info>& graph) {
    vector<int> distances(n + 1, 25000000);
    distances[1] = 0;

    for (int i = 0; i < n; i++) {
        int s, e, t;
        for (road_info info : graph) {
            s = info.s;
            e = info.e;
            t = info.t;
            distances[e] = min(distances[e], distances[s] + t);
        }
    }

    for (int i = 0; i < n; i++) {
        int s, e, t;
        for (road_info info : graph) {
            s = info.s;
            e = info.e;
            t = info.t;
            if (distances[s] + t < distances[e])
                return true;
        }
    }
    return false;
}