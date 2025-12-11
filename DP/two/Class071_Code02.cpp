#include <bits/stdc++.h>
using namespace std;

// 子序列累加和必须被7整除的最大累加和
// 给定一个非负数组nums，
// 可以任意选择数字组成子序列，但是子序列的累加和必须被7整除
// 返回最大累加和
// 对数器验证

class Code02_MaxSumDividedBy7 {
public:
    //暴力递归方法，为了测试
    static int f(vector<int> &nums, int i, int s) {
        if (i == nums.size()) {
            return s % 7 == 0 ? s : 0;
        }
        return max(f(nums, i + 1, s), f(nums, i + 1, s + nums[i]));
    }
    static int maxSum1(vector<int>& nums) {
        return f(nums, 0, 0);
    }

    static int maxSum2(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(7));
        dp[0][0] = 0;
        for (int i = 1; i < 7; i++) {
            dp[0][i] = -1;
        }
        for (int i = 1, x, cur, need; i <= n; i++) {
            x = nums[i - 1];
            cur = x % 7;
            for (int j = 0; j < 7; j++) {
                dp[i][j] = dp[i - 1][j];
                need = cur <= j ? j - cur : (j - cur + 7);
                if (dp[i - 1][need] != -1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][need] + x);
                }
            }
        }
        return dp[n][0];
    }

    static vector<int> randomArray(int n, int v) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % v;
        }
        return arr;
    }
};

int main() {
    srand((unsigned int)time(0));
    int N = 15;
    int V = 30;
    int testTime = 10000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTime; i++) {
        int len = rand() % N + 1;
        vector<int> nums = Code02_MaxSumDividedBy7::randomArray(len, V);
        int ans1 = Code02_MaxSumDividedBy7::maxSum1(nums);
        int ans2 = Code02_MaxSumDividedBy7::maxSum2(nums);
        if (ans1 != ans2) {
            cout << "出错了!" << endl;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}

