#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505, mod = 123456;
ll n, k, dp[N][N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    dp[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= 2) dp[i][0] = 2;
        int max_j = i - 2;
        for (int j = 0; j <= max_j; j++) {
            if (dp[i][j] == 0) continue;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (j + 1)) % mod;
            dp[i + 1][j + 1]  =(dp[i + 1][j + 1] + dp[i][j] * 2) % mod;
            int cnt = i - j - 2;
            if (cnt > 0) {
                dp[i + 1][j + 2] = (dp[i + 1][j + 2] + dp[i][j] * cnt) % mod;
            }
        }
    }
    cout << dp[n][k - 1] % mod << '\n';
    return 0;
}