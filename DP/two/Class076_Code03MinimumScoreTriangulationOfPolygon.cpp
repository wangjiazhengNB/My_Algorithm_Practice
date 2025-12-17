#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    //记忆化
    int minScoreTriangulation1(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f1(values, 0, n - 1, dp);
    }
    int f1(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        if (l == r) ans = 0;
        else if (l + 1 == r) ans = 0;
        else {
            for (int mid = l + 1; mid < r; mid++) {
                ans = min(ans, f1(nums, l, mid, dp) + f1(nums, mid, r, dp) + nums[mid] * nums[l] * nums[r]);
            }
        } 
        dp[l][r] = ans;
        return ans;
    }

    //严格位置依赖dp
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int l = n - 3; l >= 0; l--) {
            for (int r = l + 2; r < n; r++) {
                dp[l][r] = INT_MAX;
                for (int m = l + 1; m < r; m++) {
                    dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r] + values[m] * values[l] * values[r]);
                }
            }
        }
        return dp[0][n - 1];
    }

};

int main() {
    return 0;
}