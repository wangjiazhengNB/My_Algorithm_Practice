#include <bits/stdc++.h>
using namespace std;

// 删掉1个数字后长度为k的子数组最大累加和
// 给定一个数组nums，求必须删除一个数字后的新数组中
// 长度为k的子数组最大累加和，删除哪个数字随意
// 对数器验证
class Code06_DeleteOneNumberLengthKMaxSum {
public:
    //暴力方法，为了验证
    static int maxSum1(vector<int> &nums, int k) {
        int n = nums.size();
        if (n <= k) return 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            vector<int> rest(n);
            rest = nums;
            rest.erase(rest.begin() + i);
            ans = max(ans, lenMax(rest, k));
        }
        return ans;
    }
    static int lenMax(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i <= n - k; i++) {
            int cur = 0;
            for (int j = i, cnt = 0; cnt < k; j++, cnt++) {
                cur += nums[j];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
    static int maxSum2(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= k) return 0;
        vector<int> window(n);
        int l = 0, r = 0;
        long long sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            while (l < r && nums[window[r - 1]] >= nums[i]) {
                r--;
            }
            window[r++] = i;
            sum += nums[i];
            if (i >= k) {
                ans = max(ans, (int)(sum - nums[window[l]]));
                if (window[l] == i - k) {
                    l++;
                }
                sum -= nums[i - k];
            }
        }
        return ans;
    }
    static vector<int> randomArray(int n, int v) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = rand() % (2 * v - 1) - v;
        }
        return nums;
    }
};

int main() {
    srand((unsigned int)time(nullptr));
    int n = 200;
    int v = 1000;
    int testTimes = 10000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        int len = rand() % n + 1;
        int k = rand() % n + 1;
        vector<int> nums = Code06_DeleteOneNumberLengthKMaxSum::randomArray(len, v);
        int ans1 = Code06_DeleteOneNumberLengthKMaxSum::maxSum1(nums, k);
        int ans2 = Code06_DeleteOneNumberLengthKMaxSum::maxSum2(nums, k);
        if (ans1 != ans2) {
            cout << "出错了" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}