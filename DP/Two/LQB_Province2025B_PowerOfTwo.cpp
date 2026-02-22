#include <bits/stdc++.h>
using namespace std;

const int N = 505, K = 5005;
int n, k;
int a[N], dp[N][K];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    memset(dp, 0x3f3f3f3f, sizeof dp);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0, x; l <= min(j, 16); l++) {
                x = int(ceil(a[i] * 1.0 / (1 << l))) * (1 << l);
                if (x <= 1e5) dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + x - a[i]);
            }
        }
    }
    if (dp[n][k] == 0x3f3f3f3f) cout << -1 << endl;
    else {
        cout << dp[n][k] << endl;
    }
    return 0;
}
