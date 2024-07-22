#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int find_parent(int x, vector<int>& parent);
void union_person(int x, int y, vector<int>& parent);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int count, person;
    cin >> count;
    vector<int> truth_knowers;
    for (int i = 0; i < count; i++)
    {
        cin >> person;
        truth_knowers.emplace_back(person - 1);
    }
    
    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++) {
        int first;
        cin >> count >> first;
        parties[i].emplace_back(first - 1);
        for (int j = 1; j < count; j++) {
            cin >> person;
            parties[i].emplace_back(person - 1);
            union_person(first - 1, person - 1, parent);
        }
    }

    for (int knower : truth_knowers) {
        int knower_root = find_parent(knower, parent);
        for (int i = 0; i < n; i++) {
            if (find_parent(i, parent) == knower_root) {
                parent[i] = -1;
            }
        }
    }
    
    int answer = m;
    for (int i = 0; i < m; i++) {
        for (int p : parties[i]) {
            if (find_parent(p, parent) == -1) {
                answer--;
                break;
            }
        }
    }

    cout << answer;
    return 0;
}

int find_parent(int x, vector<int>& parent) {
    if (parent[x] == -1)
        return -1;
    if (parent[x] == x)
        return x;
    return parent[x] = find_parent(parent[x], parent);
}

void union_person(int x, int y, vector<int>& parent) {
    x = find_parent(x, parent);
    y = find_parent(y, parent);
    if (x == -1 || y == -1)
        parent[x] = parent[y] = -1;
    else
        parent[y] = x;
}