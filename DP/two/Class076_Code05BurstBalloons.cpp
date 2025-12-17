#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //记忆化
    int maxCoins1(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2);
        arr[0] = 1;
        arr[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            arr[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return f1(arr, 1, n, dp);
    }
    int f1(vector<int>& arr, int l, int r, vector<vector<int>>& dp) {
        if (l == r) return arr[l - 1] * arr[r + 1] * arr[l];
        if (dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        ans = max(
            arr[l - 1] * arr[l] * arr[r + 1] + f1(arr, l + 1, r, dp),
            arr[r + 1] * arr[r] * arr[l - 1] + f1(arr, l, r - 1, dp)
        );
        for (int k = l + 1; k < r; k++) {
            ans = max(ans, arr[l - 1] * arr[k] * arr[r + 1] + f1(arr, l, k - 1, dp) + f1(arr, k + 1, r, dp));
        }
        dp[l][r] = ans;
        return ans;
    }
    //严格位置依赖
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n + 2);
        arr[0] = 1;
        arr[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            arr[i] = nums[i - 1];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int i = 1; i <= n; i++) {
            dp[i][i] = arr[i - 1] * arr[i] * arr[i + 1];
        }
        for (int l = n, ans; l >= 1; l--) {
            for (int r = l + 1; r <= n; r++) {
                ans = max(
                    arr[l - 1] * arr[l] * arr[r + 1] + dp[l + 1][r],
                    arr[l - 1] * arr[r] * arr[r + 1] + dp[l][r - 1]
                );
                for (int k = l + 1; k < r; k++) {
                    ans = max(ans, arr[l - 1] * arr[k] * arr[r + 1] + dp[l][k - 1] + dp[k + 1][r]);
                }
                dp[l][r] = ans;
            }
        }
        return dp[1][n];
    }
};

int main() {
    return 0;
}