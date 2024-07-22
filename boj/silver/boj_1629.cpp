#include <iostream>
using namespace std;

int g_a, g_c;

long long power(long long cur, int exponent);

int main() {
    int b;
    cin >> g_a >> b >> g_c;
    cout << power(g_a, b);
    return 0;
}

long long power(long long cur, int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return cur % g_c;
    
    cur = power(cur, exponent / 2) % g_c;
    cur = cur * cur % g_c; 
    return (exponent % 2 == 0) ? cur : cur * g_a % g_c;
}