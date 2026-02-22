#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays1(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>> dp;
        return f(nums, target, 0, 0, dp);
    }
    int f(vector<int>& nums, int target, int i, int sum, auto& dp) {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }
        if (dp.count(i) && dp[i].count(sum)) {
            return dp[i][sum];
        }
        int ans = f(nums, target, i + 1, sum + nums[i], dp) + f(nums, target, i + 1, sum - nums[i], dp);
        dp[i][sum] = ans;
        return ans;
    }
    //转化为01背包类型
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum < target || (target & 1) ^ (sum & 1) == 1) return 0;
        return subsets(nums, (target + sum) >> 1);
    }
    int subsets(vector<int>& nums, int t) {
        if (t < 0) return 0;
        vector<int> dp(t + 1);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = t; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[t];
    }
};

int main() {
    return 0;
}