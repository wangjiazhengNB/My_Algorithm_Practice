#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
long long dp[2026][2][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    dp[1][0][0] = 8;
    dp[1][0][1] = 4;
    dp[1][1][0] = 2;
    dp[1][1][1] = 1;

    for (int i = 2; i <= 2025; i++) {
        dp[i][0][0] = (dp[i-1][1][1] << 3) % mod;
        dp[i][0][1] = ((dp[i-1][1][0] + dp[i-1][1][1]) << 2) % mod;
        dp[i][1][0] = ((dp[i-1][0][1] + dp[i-1][1][1]) << 1) % mod;
        dp[i][1][1] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][1][0] + dp[i-1][1][1]) % mod;
    }

    long long ans = (dp[2025][0][0] + dp[2025][0][1] + dp[2025][1][0] + dp[2025][1][1]) % mod;
    cout << ans << endl;
    return 0;
}