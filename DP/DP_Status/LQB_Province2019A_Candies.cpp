#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 21, K = 25;
const int INF = 0x3f3f3f3f;
int arr[N][K], mask[N];
int dp[1 << M];
int n, m, k;

int f(int status) {
    if ((status & ~1) == 0) return 0;
    if (dp[status] != -1) return dp[status];
    int res = INF;
    for (int i = 1; i <= n; i++) {
        int new_status = status & (~mask[i]);
        if (status != new_status) {
            res = min(res, f(new_status) + 1);
        }
    }
    dp[status] = res;
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= k; j++) {
            cin >> x;
            mask[i] |= (1 << x);
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = f((1 << (m + 1)) - 1);
    if (ans >= INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}