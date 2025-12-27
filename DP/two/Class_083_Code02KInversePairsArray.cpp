#include <bits/stdc++.h>
using namespace std;

const int N = 1005, mod = 1e9 + 7;
int dp[N][N];

class Solution {
public:
    int kInversePairs1(int n, int k) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                if (i > j) {
                    for (int p = 0; p <= j; p++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][p]) % mod;
                    }
                }
                else {
                    for (int p = j - i + 1; p <= j; p++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][p]) % mod;
                    }
                }
            }
        }
       // memset(dp, 0, sizeof dp);
        return dp[n][k];
    }

    int kInversePairs(int n, int k) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 1, window; i <= n; i++) {
            dp[i][0] = 1;
            window = dp[i][0];
            for (int j = 1; j <= k; j++) {
                if (i > j) {
                    window = (window + dp[i - 1][j]) % mod;
                }
                else {
                    window = ((window + dp[i - 1][j]) % mod - dp[i - 1][j - i] + mod) % mod;
                }
                dp[i][j] = window;
            }
        }
       // memset(dp, 0, sizeof dp);
        return dp[n][k];
    }
};

int main() {
    return 0;
}