#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long a[1005], b[1005];

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2;
        return 0;
    }
    a[1] = 1, a[2] = 6;
    b[1] = 1, b[2] = 2;
    for (int i = 3; i <= n; ++i) {
        b[i] = (2 * b[i - 1]) % MOD;
        a[i] = (2 * a[i - 1] + b[i] + 4 * a[i - 2]) % MOD;
    }
    long long sum = (4 * a[n]) % MOD;
    for (int i = 2; i < n; ++i) {
        sum = (sum + 4 * (b[i] * a[n - i] % MOD + b[n - i + 1] * a[i - 1] % MOD)) % MOD;
    }
    cout << sum;
    return 0;
}