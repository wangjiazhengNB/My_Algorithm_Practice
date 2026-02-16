#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N], n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s1, s2;
    cin >> s1;
    s2 = s1;
    n = s1.size();
    reverse(s2.begin(), s2.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << n - dp[n][n] << '\n';
    return 0;
}