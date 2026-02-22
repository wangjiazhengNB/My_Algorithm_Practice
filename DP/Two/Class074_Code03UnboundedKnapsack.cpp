#include <bits/stdc++.h>
using namespace std;

const int N = 10005, M = 10000005;
int w[N], v[N];
int m, n;

//二维版完全背包
int compute1() {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i]) dp[i][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
        }
    }
    return dp[n][m];
}

//空间压缩版
long long compute2() {
    vector<long long> dp(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    return dp[m];
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << compute2();
}