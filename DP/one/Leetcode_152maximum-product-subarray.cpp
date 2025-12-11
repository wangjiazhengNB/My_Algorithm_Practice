#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double ans = nums[0];
        double minn = nums[0], maxn = nums[0];
        //当前位置i可以为负也可以为正,i - 1位置可以为大于1的也可以为0.xx，
        //若nums[i] > 0 则 curmax = max(nums[i], nums[i] * maxn), 反之也可以
        for (int i = 1; i < n; i++) {
            int curmin = min(nums[i], (int)min(minn * nums[i], maxn * nums[i]));
            int curmax = max(nums[i], (int)max(minn * nums[i], maxn * nums[i]));
            ans = max((int)ans, curmax);
            minn = curmin;
            maxn = curmax;
        }
        return (int)ans;
    }
};

int main() {
    return 0;
}