#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //动态规划
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        int ans = max(nums[1], nums[0]);
        for (int i = 2; i < n; i++) {
            dp[i] =  dp[i - 1];
            dp[i] = max(dp[i], max(nums[i], dp[i - 2] + nums[i]));
        }
        return dp[n - 1];
    }
    
    //空间压缩
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int prepre = nums[0];
        int pre = max(nums[1], nums[0]);
        int ans = max(nums[1], nums[0]);
        for (int i = 2, cur; i < n; i++) {
            cur = max(pre, max(nums[i], prepre + nums[i]));
            prepre = pre;
            pre = cur;
        }
        return pre;
    }
};

int main() {
    return 0;
}