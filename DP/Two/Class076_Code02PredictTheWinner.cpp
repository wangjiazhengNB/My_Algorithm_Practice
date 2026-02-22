#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int first = f1(nums, 0, n - 1, dp);
        int second = sum - first;
        return first >= second;
    }
    //记忆化搜索
    int f1(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        if (dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        if (l == r) ans = nums[l];
        else {
            if (l + 1 == r) ans = max(nums[l], nums[r]);
            else {
                int p1 = nums[l] + min(f1(nums, l + 1, r - 1, dp), f1(nums, l + 2, r, dp));
                int p2 = nums[r] + min(f1(nums, l + 1, r - 1, dp), f1(nums, l, r - 2, dp));
                ans = max(p1, p2);
            }
        }
        dp[l][r] = ans;
        return ans;
    }
};

int main() {
    return 0;
}