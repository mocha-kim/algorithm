#include <iostream>
#include <vector>
using namespace std;

void preorder(char cur, vector<pair<char, char>>& tree);
void inorder(char cur, vector<pair<char, char>>& tree);
void postorder(char cur, vector<pair<char, char>>& tree);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    char p, l, r;
    vector<pair<char, char>> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> p >> l >> r;
        tree[p - 'A'].first = l;
        tree[p - 'A'].second = r;
    }

    preorder('A', tree);
    cout << "\n";
    inorder('A', tree);
    cout << "\n";
    postorder('A', tree);
    cout << "\n";

    return 0;
}

void preorder(char cur, vector<pair<char, char>>& tree) {
    int idx = cur - 'A';
    cout << cur;
    if (tree[idx].first != '.')
        preorder(tree[idx].first, tree);
    if (tree[idx].second != '.')
        preorder(tree[idx].second, tree);
}

void inorder(char cur, vector<pair<char, char>>& tree) {
    int idx = cur - 'A';
    if (tree[idx].first != '.')
        inorder(tree[idx].first, tree);
    cout << cur;
    if (tree[idx].second != '.')
        inorder(tree[idx].second, tree);
}

void postorder(char cur, vector<pair<char, char>>& tree) {
    int idx = cur - 'A';
    if (tree[idx].first != '.')
        postorder(tree[idx].first, tree);
    if (tree[idx].second != '.')
        postorder(tree[idx].second, tree);
    cout << cur;
}