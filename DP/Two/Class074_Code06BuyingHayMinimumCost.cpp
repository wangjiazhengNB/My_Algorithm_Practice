#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, m;
int w[N], v[N];

int compute(int maxv) {
    int k = m + maxv;
    vector<vector<int>> dp(n + 1, vector<int>(k, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i] && dp[i][j - w[i]] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = m; i < k; i++) {
        if (dp[n][i] != INT_MAX) ans = min(ans, dp[n][i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        maxv = max(maxv, w[i]);
    }
    cout << compute(maxv);
    return 0;
}