#include <bits/stdc++.h>
using namespace std;

class Find {
public:
    //暴力方法，为了测试
    static int find1(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    
    //dp+二分
    static int find2(vector<int> nums) {
        int n = nums.size();
        vector<int> ends(n);
        int len = 0;
        for (int i = 0, find; i < n; i++) {
            find = bs1(ends, len, nums[i]);
            if (find == -1) {
                ends[len++] = nums[i];
            }
            else {
                ends[find] = nums[i];
            }
        }
        return len;
    }

    // "最长递增子序列"使用如下二分搜索 :
	// ends[0...len-1]是严格升序的，找到>=num的最左位置
	// 如果不存在返回-1
    static int bs1(vector<int>& ends, int len, int num) {
        int l = 0, r = len - 1, mid, ans = -1;
        while (l <= r) {
            mid = l + r >> 1;
            if (ends[mid] >= num) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }

    // 如果求最长不下降子序列，那么使用如下的二分搜索 :
	// ends[0...len-1]是不降序的
	// 在其中找到>num的最左位置，如果不存在返回-1
	// 如果求最长不下降子序列，就在lengthOfLIS中把bs1方法换成bs2方法
	// 已经用对数器验证了，是正确的
    static int bs2(vector<int>& ends, int len, int num) {
        int l = 0, r = len - 1, mid, ans = -1;
        while (l <= r) {
            mid = l + r >> 1;
            if (ends[mid] > num) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}