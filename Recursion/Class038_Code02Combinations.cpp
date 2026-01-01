#include <bits/stdc++.h>
using namespace std;

void f(vector<int>& nums, int i, vector<int>& path, int size, vector<vector<int>>& ans) {
    if (i == nums.size()) {
        vector<int> cur;
        for (int j = 0; j < size; j++) {
            cur.push_back(path[j]);
        }
        ans.push_back(cur);
    } else {
        int j = i + 1;
        while (j < nums.size() && nums[i] == nums[j]) {
            j++;
        }
        f(nums, j, path, size, ans);
        for (; i < j; i++) {
            path[size++] = nums[i];
            f(nums, j, path, size, ans);
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path(n);
    sort(nums.begin(), nums.end());
    f(nums, 0, path, 0, ans);
    return ans;
}

void printResult(vector<vector<int>>& res) {
    for (auto& vec : res) {
        cout << "[";
        for (int k = 0; k < vec.size(); k++) {
            cout << vec[k];
            if (k != vec.size() - 1) {
                cout << ",";
            }
        }
        cout << "] ";
    }
    cout << endl;
}

int main() {
    // 测试案例1：含重复元素（核心测试）
    vector<int> nums1 = {1,2,2};
    vector<vector<int>> res1 = subsetsWithDup(nums1);
    cout << "测试案例1 [1,2,2] 结果：" << endl;
    printResult(res1);

    // 测试案例2：无重复元素
    vector<int> nums2 = {1,2,3};
    vector<vector<int>> res2 = subsetsWithDup(nums2);
    cout << "测试案例2 [1,2,3] 结果：" << endl;
    printResult(res2);

    // 测试案例3：单个元素
    vector<int> nums3 = {2};
    vector<vector<int>> res3 = subsetsWithDup(nums3);
    cout << "测试案例3 [2] 结果：" << endl;
    printResult(res3);

    // 测试案例4：空数组
    vector<int> nums4 = {};
    vector<vector<int>> res4 = subsetsWithDup(nums4);
    cout << "测试案例4 [] 结果：" << endl;
    printResult(res4);

    return 0;
}