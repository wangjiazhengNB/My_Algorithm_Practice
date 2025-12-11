#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            l = min(l, nums[i]);
            r = max(r, nums[i]);
        }
        int mid, ans = l;
        while (l <= r) {
            mid = l + r >> 1;
            if (check(nums, n, mid) >= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
    //动态规划
    int check1(vector<int>& nums, int n, int ability) {
        if (n == 1) return ability >= nums[0] ? 1 : 0;
        if (n == 2) return (ability >= nums[0] || ability >= nums[1]) ? 1 : 0;
        vector<int> dp(n);
        dp[0] = ability >= nums[0] ? 1 : 0;
        dp[1] = (ability >= nums[0] || ability >= nums[1]) ? 1 : 0;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 2];
            if (ability >= nums[i]) {
                dp[i] = dp[i] + 1;
            }
            dp[i] = max(dp[i - 1], dp[i]);
        }
        return dp[n - 1];
    }

    //空间压缩
    int check(vector<int>& nums, int n, int ability) {
        if (n == 1) return ability >= nums[0] ? 1 : 0;
        if (n == 2) return (ability >= nums[0] || ability >= nums[1]) ? 1 : 0;
        int prepre = ability >= nums[0] ? 1 : 0;
        int pre = (ability >= nums[0] || ability >= nums[1]) ? 1 : 0;
        for (int i = 2, cur; i < n; i++) {
            cur = prepre;
            if (ability >= nums[i]) {
                cur = cur + 1;
            }
            cur = max(pre, cur);
            prepre = pre;
            pre = cur;
        }
        return pre;
    }

    //贪心
    int check(vector<int>& nums, int n, int ability) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (ability >= nums[i]) {
                ans++;
                i++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}