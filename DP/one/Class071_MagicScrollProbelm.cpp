#include <bits/stdc++.h>
using namespace std;

// 魔法卷轴
// 给定一个数组nums，其中可能有正、负、0
// 每个魔法卷轴可以把nums中连续的一段全变成0
// 你希望数组整体的累加和尽可能大
// 卷轴使不使用、使用多少随意，但一共只有2个魔法卷轴
// 请返回数组尽可能大的累加和
// 对数器验证

int mustOneScroll(vector<int>& nums, int l, int r) {
    int ans = INT_MIN;
    for (int a = l; a <= r; a++) {
        for (int b = a; b <= r; b++) {
            int cost = 0;
            for (int i = l; i < a; i++) {
                cost += nums[i];
            }
            for (int i = b + 1; i <= r; i++) {
                cost += nums[i];
            }
            ans = max(cost, ans);
        }
    }
    return ans;
}

//暴力做法，为了测试
int maxSum1(vector<int> &nums) {
    int p1 = 0;
    for (int num : nums) {
        p1 += num;
    }
    int n = nums.size();
    int p2 = mustOneScroll(nums, 0, n - 1);
    int p3 = INT_MIN;
    for (int i = 1; i < n; i++) {
        p3 = max(p3, mustOneScroll(nums, 0, i - 1) + mustOneScroll(nums, i, n - 1));
    }
    return max(p1, max(p2, p3));
}

//动态规划O(n)
int maxSum2(vector<int>& nums) {
    int n = nums.size();
    if (nums.size() == 0) return 0;
    int p1 = 0;
    for (int num : nums) {
        p1 += num;
    }
    vector<int> prefix(n);
    int sum = nums[0];
    int maxPresum = max(0, nums[0]);
    for (int i = 1; i < n; i++) {
        prefix[i] = max(maxPresum, prefix[i - 1] + nums[i]);
        sum += nums[i];
        maxPresum = max(maxPresum, sum);
    }
    int p2 = prefix[n - 1];
    vector<int> suffix(n);
    sum = nums[n - 1];
    int maxSufsum = max(0, nums[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(maxSufsum, suffix[i + 1] + nums[i]);
        sum += nums[i];
        maxSufsum = max(maxSufsum, sum);
    }
    int p3 = INT_MIN;
    for (int i = 1; i < n; i++) {
        p3 = max(p3, prefix[i - 1] + suffix[i]);
    }
    return max(p1, max(p2, p3));
}

vector<int> randomArray(int n, int v) {
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = (rand() % (v * 2 + 1) - v);
    }
    return nums;
}


int main() {
    srand((unsigned int)time(0));
    int n = 50;
    int v = 100;
    int testTime = 10000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTime; i++) {
        int len = rand() % n + 1;
        vector<int> nums = randomArray(len, v);
        int ans1 = maxSum1(nums);
        int ans2 = maxSum2(nums);
        if (ans1 != ans2) {
            cout << "出错了" << endl;
            break;
        }
    }
    cout << "测试结束" << endl;
    return 0;
}