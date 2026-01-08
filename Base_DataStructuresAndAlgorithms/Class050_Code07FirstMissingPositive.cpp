#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            if (nums[l] == l + 1) {
                l++;
            }
            else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) {
                swap(nums, l, --r);
            }
            else {
                swap(nums, l, nums[l] - 1);
            }
        }
        return l + 1;
    }
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};

int main() {
    return 0;
}