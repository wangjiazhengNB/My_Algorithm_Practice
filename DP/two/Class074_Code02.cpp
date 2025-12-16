#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //严格位置依赖做法
    int maxValueOfCoins1(vector<vector<int>>& piles, int m) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            vector<int> teams = piles[i - 1];
            int t = min((int)teams.size(), m);
            vector<int> preSum(t + 1);
            for (int j = 0, sum = 0; j < t; j++) {
                sum += teams[j];
                preSum[j + 1] = sum;
            }
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k <= min(t, j); k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + preSum[k]);
                }
            }
        }
        return dp[n][m];
    }

    //空间压缩
    int maxValueOfCoins(vector<vector<int>>& piles, int m) {
        int n = piles.size();
        vector<int> dp(m + 1);
        for (int i = 1; i <= n; i++) {
            vector<int> teams = piles[i - 1];
            int t = min((int)teams.size(), m);
            vector<int> preSum(t + 1);
            for (int j = 0, sum = 0; j < t; j++) {
                sum += teams[j];
                preSum[j + 1] = sum;
            }
            for (int j = m; j > 0; j--) {
                for (int k = 1; k <= min(t, j); k++) {
                    dp[j] = max(dp[j], dp[j - k] + preSum[k]);
                }
            }
        }
        return dp[m];
    }
};

int main() {
    return 0;
}