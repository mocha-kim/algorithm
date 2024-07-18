#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    string op;
    int x;
    bool s[21] = { false };
    for (int i = 0; i < m; i++) {
        cin >> op;
        switch (op[0])
        {
        case 'a':
            if (op[1] == 'd') {
                cin >> x;
                s[x] = true;
            } else {
                memset(s, true, sizeof(s));
            }
            break;
        case 'r':
            cin >> x;
            s[x] = false;
            break;
        case 'c':
            cin >> x;
            cout << (s[x] ? 1 : 0) << "\n";
            break;
        case 't':
            cin >> x;
            s[x] = !s[x];
            break;
        case 'e':
            memset(s, false, sizeof(s));
            break;
        default:
            break;
        }
    }
    return 0;
}