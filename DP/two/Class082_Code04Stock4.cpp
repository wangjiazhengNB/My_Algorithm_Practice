#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int free(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += max(0, prices[i + 1] - prices[i]);
        }
        return ans;
    }
    //没有进行枚举优化版本的
    int maxProfit1(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            return free(prices);
        }
        vector<vector<int>> dp(k + 1, vector<int>(n));
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1];
                for (int p = 0; p < j; p++) {
                    dp[i][j] = max(dp[i][j], dp[i][p] + prices[j] - prices[p]);
                }
            }
        }
        return dp[k][n - 1];
    }
    //枚举优化版本的
    int maxProfit2(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            return free(prices);
        }
        vector<vector<int>> dp(k + 1, vector<int>(n));
        for (int i = 1, best; i <= k; i++) {
            best = dp[i - 1][0] - prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], best + prices[j]);
                best = max(best, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
    //空间压缩
     int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            return free(prices);
        }
        vector<int> dp(n);
        for (int i = 1, best; i <= k; i++) {
            best = dp[0] - prices[0];
            for (int j = 1; j < n; j++) {
                int tmp = dp[j];
                dp[j] = max(dp[j - 1], best + prices[j]);
                best = max(best, tmp - prices[j]);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    return 0;
}