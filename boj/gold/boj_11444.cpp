#include <iostream>
#include <unordered_map>
using namespace std;

#define MOD 1000000007ll

unordered_map<long long, long long> g_memo;

long long fibonacci(long long n);

int main() {
    long long n;
    cin >> n;

    g_memo[0] = 0;
    g_memo[1] = 1;
    g_memo[2] = 1;
    cout << fibonacci(n);
    return 0;
}

long long fibonacci(long long n) {
    if (g_memo.count(n) == 1)
        return g_memo[n];

    if (n % 2 == 0) {
        long long half = n / 2;
        g_memo[n] = (fibonacci(half) * (fibonacci(half + 1) + fibonacci(half - 1))) % MOD;
    } else {
        long long tmp1 = (fibonacci((n + 1) / 2) * fibonacci((n + 1) / 2)) % MOD;
        long long tmp2 = (fibonacci((n - 1) / 2) * fibonacci((n - 1) / 2)) % MOD;
        g_memo[n] = (tmp1 + tmp2) % MOD;
    }
    return g_memo[n];
}