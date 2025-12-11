#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int all = nums[0], maxsum = nums[0], minsum = nums[0];
        for (int i = 1, maxpre = nums[0], minpre = nums[0]; i < n; i++) {
            all += nums[i];
            maxpre = max(nums[i], maxpre + nums[i]);
            maxsum = max(maxsum, maxpre);
            minpre = min(nums[i], minpre + nums[i]);
            minsum = min(minsum, minpre);
        }
        return all == minsum ? maxsum : max(all - minsum, maxsum);
    }
};

int main() {
    return 0;
}