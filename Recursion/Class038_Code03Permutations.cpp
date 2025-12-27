#include <bits/stdc++.h>

using namespace std;

void swaps(vector<int>& nums, int i, int j);

void f(vector<int>& nums, int i, vector<vector<int>>& ans) {
    if (i == nums.size()) {
        vector<int> cur;
        for (int num : nums) {
            cur.push_back(num);
        }
        ans.push_back(cur);
    } else {
        for (int j = i; j < nums.size(); ++j) {
            swaps(nums, i, j);
            f(nums, i + 1, ans);
            swaps(nums, i, j);
        }
    }
}

void swaps(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    f(nums, 0, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    
    for (vector<int>& list : ans) {
        for (int num : list) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}