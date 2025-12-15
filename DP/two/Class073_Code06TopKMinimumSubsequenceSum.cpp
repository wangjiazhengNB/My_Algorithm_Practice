#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

//暴力方法，为了测试
void f1(vector<int>& nums, int i, int sum, vector<int>& ans) {
    if (i == nums.size()) {
        ans.push_back(sum);
    }
    else {
        f1(nums, i + 1, sum, ans);
        f1(nums, i + 1, sum + nums[i], ans);
    }
}

//暴力方法，为了测试
vector<int> topKSum1(vector<int>& nums, int k) {
    vector<int> allSubsequences;
    f1(nums, 0, 0, allSubsequences);
    sort(allSubsequences.begin(), allSubsequences.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++) {
        ans[i] = allSubsequences[i];
    }
    return ans;
}

//01背包实现（非最优解）
vector<int> topKSum2(vector<int>& nums, int k) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int num : nums) {
        for (int j = sum; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    vector<int> ans(k);
    int index = 0;
    for (int j = 0; j <= sum && index < k; j++) {
        for (int i = 0; i < dp[j] && index < k; i++) {
            ans[index++] = j;
        }
    }
    return ans;
}

//运用堆实现（前提不能有负值）
vector<int> topKSum3(vector<int>& nums, int k) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    sort(nums.begin(), nums.end());
    heap.push({nums[0], 0});
    vector<int> ans(k, 0);
    for (int i = 1; i < k; i++) {
        auto cur = heap.top();
        heap.pop();
        int sum = cur.first;
        int right = cur.second;
        ans[i] = sum;
        if (right + 1 < nums.size()) {
            heap.push({sum + nums[right + 1], right + 1});
            heap.push({sum - nums[right] + nums[right + 1], right + 1});
        }
    }
    return ans;
}

vector<int> randomArray(int n, int v) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % v + 1;
    }
    return arr;
}

int main() {
    srand((unsigned int)time(nullptr));
    int n = 15;
    int v = 200;
    int testTime = 1000;
    cout << "测试开始" << endl;
    for (int i = 0; i < testTime; i++) {
        int len = rand() % n + 1;
        int maxk = (1 << len) - 1;
        int k = rand() % maxk + 1;
        vector<int> nums = randomArray(len, v);
        vector<int> ans1, ans2, ans3;
        ans1 = topKSum1(nums, k);
        ans2 = topKSum2(nums, k);
        ans3 = topKSum3(nums, k);
        if (ans1 != ans2 || ans1 != ans3) {
            cout << "出错了" << endl;
        } 
    }
    cout << "测试结束" << endl;
    return 0;
}