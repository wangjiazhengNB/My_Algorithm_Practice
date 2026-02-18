#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;
ll dp[N][N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 1; j <= m; j++) dp[0][j] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
            else {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}