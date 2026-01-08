#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for (int odd = 1, even = 0, tmp; odd < n && even < n;) {
            if ((nums[n - 1] & 1) == 1) {
                tmp = nums[n - 1];
                nums[n - 1] = nums[odd];
                nums[odd] = tmp;
                odd += 2;
            }
            else {
                tmp = nums[n - 1];
                nums[n - 1] = nums[even];
                nums[even] = tmp;
                even += 2;
            }
        }
        return nums;
    }
};

int main() {
    return 0;
}